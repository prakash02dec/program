import java.util.Scanner;

public class QuestionService {
    private Question[] questions = new Question[5] ;
    String selection[] = new String[5] ;
    public QuestionService(){
        questions[0] = new Question(1, "What is the capital of India?", "Delhi", "Mumbai", "Kolkata", "Chennai", "Delhi") ;
        questions[1] = new Question(2, "What is the capital of USA?", "Washington DC", "New York", "Los Angeles", "Chicago", "Washington DC") ;
        questions[2] = new Question(3, "What is the capital of UK?", "London", "Manchester", "Birmingham", "Liverpool", "London") ;
        questions[3] = new Question(4, "What is the capital of Australia?", "Canberra", "Sydney", "Melbourne", "Brisbane", "Canberra") ;
        questions[4] = new Question(5, "What is the capital of Japan?", "Tokyo", "Osaka", "Kyoto", "Hiroshima", "Tokyo") ;
    }
    public void displayQuestion(){
        for(Question q : questions){
            System.out.println(q) ;
        }
    }
    public void playQuiz(){
        int i = 0 ;
        for(Question q : questions){
            System.out.println(q.getQuestion());
            System.out.println("A. " + q.getOpt1());
            System.out.println("B. " + q.getOpt2());
            System.out.println("C. " + q.getOpt3());
            System.out.println("D. " + q.getOpt4());
            System.out.println("Enter your answer: ");
            Scanner sc = new Scanner(System.in) ;
            selection[i] = sc.nextLine() ;
            i++ ;
        }

        for(String s : selection){
            System.out.println(s);
        }

    }
    public void printScore(){
        int score = 0 ;
        for(int i = 0; i < questions.length; i++){
            if(questions[i].getAnswer().equals(selection[i])){
                score++ ;
            }
        }
        System.out.println("Your score is: " + score);
    }
}
