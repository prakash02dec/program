package transaction.model;

import java.time.LocalDateTime;

public class Transaction {
    int transactionId;
    int senderUserId ; 
    int receiverUserId ;
    int sendInstrumentId ; 
    int receiveInstrumentId ;
    int amount ; 
    int paymentId;
    TransactionStatus status;
    LocalDateTime createdAt;
    LocalDateTime updatedAt;

    public int getTransactionId() {
        return transactionId;
    }
    public void setTransactionId(int transactionId) {
        this.transactionId = transactionId;
    }
    public int getSenderUserId() {
        return senderUserId;
    }
    public void setSenderUserId(int senderUserId) {
        this.senderUserId = senderUserId;
    }
    public int getReceiverUserId() {
        return receiverUserId;
    }
    public void setReceiverUserId(int receiverUserId) {
        this.receiverUserId = receiverUserId;
    }

    public int getSendInstrumentId() {
        return sendInstrumentId;
    }
    public void setSendInstrumentId(int sendInstrumentId) {
        this.sendInstrumentId = sendInstrumentId;
    }
    public int getReceiveInstrumentId() {
        return receiveInstrumentId;
    }
    public void setReceiveInstrumentId(int receiveInstrumentId) {
        this.receiveInstrumentId = receiveInstrumentId;
    }
    public int getAmount() {
        return amount;
    }
    public void setAmount(int amount) {
        this.amount = amount;
    }
    public int getPaymentId() {
        return paymentId;
    }
    public void setPaymentId(int paymentId) {
        this.paymentId = paymentId;
    }
    public TransactionStatus getStatus() {
        return status;
    }
    public void setStatus(TransactionStatus status) {
        this.status = status;
    }
    public LocalDateTime getCreatedAt() {
        return createdAt;
    }
    public void setCreatedAt(LocalDateTime createdAt) {
        this.createdAt = createdAt;
    }
    public LocalDateTime getUpdatedAt() {
        return updatedAt;
    }
    public void setUpdatedAt(LocalDateTime updatedAt) {
        this.updatedAt = updatedAt;
    }

    @Override
    public String toString() {
        return "Transaction [transactionId=" + transactionId + ", senderUserId=" + senderUserId + ", receiverUserId=" + receiverUserId
                + ", sendInstrumentId=" + sendInstrumentId + ", receiveInstrumentId=" + receiveInstrumentId
                + ", amount=" + amount + ", paymentId=" + paymentId + ", status=" + status
                + ", createdAt=" + createdAt + ", updatedAt=" + updatedAt + "]";
    }   

}
