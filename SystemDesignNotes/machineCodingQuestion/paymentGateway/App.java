import user.service.*;
import instrument.model.*;
import instrument.*;
import transaction.*;
import transaction.model.*;

public class App {
    public static void main(String[] args) {
        System.out.println("=== Payment Gateway Sample Run ===\n");
        
        // 1. Create User Service and add users
        System.out.println("--- Step 1: Creating Users ---");
        UserService userService = new UserService();
        
        UserDoa user1Doa = new UserDoa();
        user1Doa.setName("Prakash Singh");
        user1Doa.setMail("prakash@example.com");
        user1Doa.setPhoneNo("9876543210");
        UserDoa createdUser1 = userService.addUser(user1Doa);
        System.out.println("User 1 Created: " + createdUser1.getName() + " (ID: " + createdUser1.getId() + ")");
        
        UserDoa user2Doa = new UserDoa();
        user2Doa.setName("Rajesh Kumar");
        user2Doa.setMail("rajesh@example.com");
        user2Doa.setPhoneNo("9876543211");
        UserDoa createdUser2 = userService.addUser(user2Doa);
        System.out.println("User 2 Created: " + createdUser2.getName() + " (ID: " + createdUser2.getId() + ")");
        
        int senderId = createdUser1.getId();
        int receiverId = createdUser2.getId();
        
        // 2. Add payment instruments (cards and bank accounts)
        System.out.println("\n--- Step 2: Adding Payment Instruments ---");
        InstrumentController instrumentController = new InstrumentController();
        
        // Add Card for User 1
        InstrumentDoa cardInstrument1 = new InstrumentDoa();
        cardInstrument1.setType(InstrumentType.CARD);
        cardInstrument1.setUserId(senderId);
        cardInstrument1.setCardNumber("4532-1234-5678-9010");
        cardInstrument1.setCvv("123");
        InstrumentDoa addedCard1 = instrumentController.addInstrument(cardInstrument1);
        System.out.println("Card added for User 1 (Instrument ID: " + addedCard1.getInstrumentId() + ")");
        System.out.println("  Card Number: " + addedCard1.getCardNumber());
        
        // Add Bank Account for User 1
        InstrumentDoa bankInstrument1 = new InstrumentDoa();
        bankInstrument1.setType(InstrumentType.BANK);
        bankInstrument1.setUserId(senderId);
        bankInstrument1.setAccountNo("1234567890");
        bankInstrument1.setIfsc("HDFC0001234");
        InstrumentDoa addedBank1 = instrumentController.addInstrument(bankInstrument1);
        System.out.println("Bank account added for User 1 (Instrument ID: " + addedBank1.getInstrumentId() + ")");
        System.out.println("  Account Number: " + addedBank1.getAccountNo());
        
        // Add Bank Account for User 2 (as receiver)
        InstrumentDoa bankInstrument2 = new InstrumentDoa();
        bankInstrument2.setType(InstrumentType.BANK);
        bankInstrument2.setUserId(receiverId);
        bankInstrument2.setAccountNo("9876543210");
        bankInstrument2.setIfsc("ICIC0005678");
        InstrumentDoa addedBank2 = instrumentController.addInstrument(bankInstrument2);
        System.out.println("Bank account added for User 2 (Instrument ID: " + addedBank2.getInstrumentId() + ")");
        System.out.println("  Account Number: " + addedBank2.getAccountNo());
        
        // 3. Create and process transactions
        System.out.println("\n--- Step 3: Creating Transactions ---");
        TransactionController transactionController = new TransactionController();
        
        // Transaction 1: Card to Bank (User 1 to User 2)
        System.out.println("\nTransaction 1: Sending Rs. 5000 from User 1 (via Card) to User 2");
        Transaction txn1 = new Transaction();
        txn1.setSenderUserId(senderId);
        txn1.setReceiverUserId(receiverId);
        txn1.setSendInstrumentId(addedCard1.getInstrumentId());
        txn1.setReceiveInstrumentId(addedBank2.getInstrumentId());
        txn1.setAmount(5000);
        
        Transaction processedTxn1 = transactionController.createTransaction(txn1);
        System.out.println("Transaction ID: " + processedTxn1.getTransactionId());
        System.out.println("Amount: Rs. " + processedTxn1.getAmount());
        System.out.println("Status: " + processedTxn1.getStatus());
        
        // Transaction 2: Bank to Bank (User 1 to User 2)
        System.out.println("\nTransaction 2: Sending Rs. 10000 from User 1 (via Bank) to User 2");
        Transaction txn2 = new Transaction();
        txn2.setSenderUserId(senderId);
        txn2.setReceiverUserId(receiverId);
        txn2.setSendInstrumentId(addedBank1.getInstrumentId());
        txn2.setReceiveInstrumentId(addedBank2.getInstrumentId());
        txn2.setAmount(10000);
        
        Transaction processedTxn2 = transactionController.createTransaction(txn2);
        System.out.println("Transaction ID: " + processedTxn2.getTransactionId());
        System.out.println("Amount: Rs. " + processedTxn2.getAmount());
        System.out.println("Status: " + processedTxn2.getStatus());
        
        // 4. Display transaction history
        System.out.println("\n--- Step 4: Transaction History for User 1 ---");
        transactionController.display(senderId);
        
        System.out.println("\n=== Payment Gateway Sample Run Completed ===");
    }
}
