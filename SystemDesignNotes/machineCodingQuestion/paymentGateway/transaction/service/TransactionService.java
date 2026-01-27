package transaction.service;
import payment.*;
import payment.model.*;
import transaction.model.*;
import java.util.* ;
import java.time.LocalDateTime;
import instrument.InstrumentController;
import instrument.model.*;

public class TransactionService {
    PaymentService paymentService ;
    InstrumentController instrumentService ;
    static Map<Integer, ArrayList<Transaction>> transactionStore = new HashMap<>();

    public TransactionService() {
        paymentService = new PaymentService();
        instrumentService = new InstrumentController();
    }
    
    public ArrayList<Transaction> getTransactionsByUserId(int userId) {
        return transactionStore.getOrDefault(userId, new ArrayList<>());
    }

    public Transaction createTransaction(Transaction transaction) {
        transaction.setTransactionId((int) new Random().nextInt(10000-1000)+1000);
        transaction.setCreatedAt(LocalDateTime.now());
        transaction.setUpdatedAt(LocalDateTime.now());

        transaction.setStatus(TransactionStatus.INITIATED);


        PaymentDao paymentDao = new PaymentDao();
        InstrumentDoa senderInstrument = instrumentService.getByInstrumentId(transaction.getSenderUserId() , transaction.getSendInstrumentId());
        InstrumentDoa receiverInstrument = instrumentService.getByInstrumentId(transaction.getReceiverUserId() , transaction.getReceiveInstrumentId());
        paymentDao.setSenderInstrument(senderInstrument);
        paymentDao.setReceiverInstrument(receiverInstrument);
        paymentDao.setAmount(transaction.getAmount());


        PaymentDao processedPayment = paymentService.payment(paymentDao);
        transaction.setPaymentId(processedPayment.getPaymentId());
        transaction.setStatus(TransactionStatus.PENDING);


        if (processedPayment != null && processedPayment.getStatus() == PaymentStatus.SUCCESS) {
            transaction.setStatus(TransactionStatus.SUCCESS);
        } else {
            transaction.setStatus(TransactionStatus.FAILED);
        }

        ArrayList<Transaction> userTransactions = transactionStore.getOrDefault(transaction.getSenderUserId(), new ArrayList<>());
        userTransactions.add(transaction);
        transactionStore.put(transaction.getSenderUserId(), userTransactions);

        return transaction;
    }

}
