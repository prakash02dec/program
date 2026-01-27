package transaction;

import transaction.service.TransactionService;
import transaction.model.* ; 

import java.util.* ;
public class TransactionController {
    private TransactionService transactionService = new TransactionService();
    public Transaction createTransaction(Transaction transaction) {
        return transactionService.createTransaction(transaction);
    }

    public void display(int userId) {
        ArrayList<Transaction> transactions = transactionService.getTransactionsByUserId(userId);
        for(Transaction t : transactions) {
            System.out.println(t);
        }
    }

}
