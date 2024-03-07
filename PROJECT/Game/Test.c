#include <stdio.h>
#include <time.h>
#include <string.h>  // Added for strcpy and strcspn

typedef struct {
  int questionNumber;
  char question[256];
  int correctAnswer;
} Question;

Question createQuestion(int number, const char* question, int correctAnswer) {
  Question q;
  q.questionNumber = number;
  strcpy(q.question, question);
  q.correctAnswer = correctAnswer;
  return q;
}

void displayQuestion(Question q) {
  printf("Question %d: %s\n", q.questionNumber, q.question);
}

int calculateScore(Question* questions, int numQuestions, char* userAnswers) {
  int score = 0;
  for (int i = 0; i < numQuestions; i++) {
    if (userAnswers[i] == 'T' || userAnswers[i] == 't') {
      if (questions[i].correctAnswer == 1) {
        score++;
      }
    } else if (userAnswers[i] == 'F' || userAnswers[i] == 'f') {
      if (questions[i].correctAnswer == 0) {
        score++;
      }
    }
  }
  return score;
}

int main() {
  char firstName[50], lastName[50];
  time_t currentTime, start_time;
  struct tm* timeInfo;
  int elapsedSeconds;

  printf("Enter your first name: ");
  fgets(firstName, sizeof(firstName), stdin);
  firstName[strcspn(firstName, "\n")] = '\0';

  printf("Enter your last name: ");
  fgets(lastName, sizeof(lastName), stdin);
  lastName[strcspn(lastName, "\n")] = '\0';

  time(&start_time);
  timeInfo = localtime(&start_time);

  printf("Name: %s %s | Date and Time: %02d/%02d/%d %02d:%02d:%02d\n",
         firstName, lastName,
         timeInfo->tm_mday, timeInfo->tm_mon + 1, timeInfo->tm_year + 1900,
         timeInfo->tm_hour, timeInfo->tm_min, timeInfo->tm_sec);

  Question questions[50];
  questions[0] = createQuestion(1, "What is the capital of France? = Paris? ", 1); 
    questions[1] = createQuestion(2, "Who wrote To Kill a Mockingbird? = Shakespeare?", 0); 
   questions[1] = createQuestion(2, "Who wrote To Kill a Mockingbird? = Shakespeare?", 0); 
    questions[2] = createQuestion(3, "What is the chemical symbol for water? = H2O2?", 1);
    questions[3] = createQuestion(4, "When did World War II end? = 1918? ", 1);
    questions[4] = createQuestion(5, "What is the tallest mountain in the world? = Mount Kilimanjaro? ", 1);
    questions[5] = createQuestion(6, "Who painted the Mona Lisa? = Vincent van Gogh? ", 1);
    questions[6] = createQuestion(7, "What is the currency of Japan? = Euro? ", 1);
    questions[7] = createQuestion(8, "How many continents are there? = Seven? ", 1);
    questions[8] = createQuestion(9, "Who is the current president of the United States? = Barack Obama? ", 1);
    questions[9] = createQuestion(10, "Who painted the Mona Lisa? = Pablo Picasso? ", 1);
    questions[10] = createQuestion(11, "What is the largest planet in our solar system? = Saturn? (T/F)", 1);
    questions[11] = createQuestion(12, "Who wrote Romeo and Juliet? = Charles Dickens? (T/F)", 1);
    questions[12] = createQuestion(13, "What is the chemical symbol for water? = H2SO4? (T/F)", 1);
    questions[13] = createQuestion(14, "Which animal is known as the King of the Jungle? =  Elephant? (T/F)", 1);
    questions[14] = createQuestion(15, "What is the currency of Japan? = Dollar? ", 1);
    questions[15] = createQuestion(16, "Who invented the telephone? = Thomas Edison? ", 1);
    questions[16] = createQuestion(17, "What is the main ingredient in guacamole? = Tomato? ", 1);
    questions[17] = createQuestion(18, "What is the square root of 64?? = 10? (T/F)", 1);
    questions[18] = createQuestion(19, "What is the speed of light in a vacuum? = 300,000 meters per second? ", 1);
    questions[19] = createQuestion(20, "Who is the author of To Kill a Mockingbird? = Mark Twain? ", 1);
    questions[20] = createQuestion(21, "What is the chemical symbol for gold? = Gd? ", 1);
    questions[21] = createQuestion(22, "What is the tallest mammal? =  Elephant? ", 1);
    questions[22] = createQuestion(23, "What is the boiling point of water in Celsius? = 50 degrees? (", 1);
    questions[23] = createQuestion(24, "What is the capital of Spain? =  Barcelona? ", 1);
    questions[24] = createQuestion(25, "What is the chemical formula for table salt? = NaCO3? ", 1);
    questions[25] = createQuestion(26, "What is the smallest prime number? = 1?   ", 1);
    questions[26] = createQuestion(27, "Who composed the Moonlight Sonata ? = Mozart? ", 1);
    questions[27] = createQuestion(28, "What is the largest ocean on Earth? = Indian Ocean? ", 1);
    questions[28] = createQuestion(29, "What is the freezing point of water in Fahrenheit? = 30 degrees?", 1);
    questions[29] = createQuestion(30, "What is the diameter of Earth? = Approximately 10,000 kilometers? ", 1);
    questions[30] = createQuestion(31, "What is the boiling point of water in Kelvin? = 400 Kelvin? ", 1);
    questions[31] = createQuestion(32, "What is the capital of Brazil? = Rio de Janeiro? = Marie Curie", 1);
    questions[32] = createQuestion(33, "Who wrote The Great Gatsby ? = Ernest Hemingway?", 1);
    questions[33] = createQuestion(34, "What is the chemical symbol for oxygen? = Ox? ", 1);
    questions[34] = createQuestion(35, "What is the main component of Earth's atmosphere? = Carbon dioxide? ", 1);
    questions[35] = createQuestion(36, "What is the chemical symbol for carbon dioxide? = CO3?", 1);
    questions[36] = createQuestion(37, "Who painted Starry Night? = Leonardo da Vinci?", 1);
    questions[37] = createQuestion(38, "What is the freezing point of water in Kelvin? = 300 Kelvin?", 1);
    questions[38] = createQuestion(39, "Who developed the theory of relativity? = Isaac Newton?", 1);
    questions[39] = createQuestion(40, "What is the chemical formula for glucose? = CH4?", 1);
    questions[40] = createQuestion(41, "What is the boiling point of water in Fahrenheit? = 200 degrees? )", 1);
    questions[41] = createQuestion(42, "Who wrote 1984? = J.K. Rowling?", 1);
    questions[42] = createQuestion(43, "What is the chemical symbol for helium? = H?", 1);
    questions[43] = createQuestion(44, "What is the largest mammal on Earth? = Elephant? ", 1);
    questions[44] = createQuestion(45, "Who composed The Four Seasons ? = Bach? ", 1);
    questions[45] = createQuestion(46, "What is the capital of Italy? = Milan? ", 1);
    questions[46] = createQuestion(47, "Who discovered America? = Amerigo Vespucci?", 1);
    questions[47] = createQuestion(48, "What is the chemical symbol for iron? = Ir? ", 1);
    questions[48] = createQuestion(49, "Who wrote Pride and Prejudice? = Emily Bronte? ", 1);
    questions[49] = createQuestion(50, "What is the chemical formula for water? = H3O? ", 1);

  char userAnswers[50]; 

  for (int i = 0; i < 50; i++) {
    displayQuestion(questions[i]);

    char userAnswer;
    printf("Enter your answer (T/F): ");
    scanf(" %c", &userAnswer);

    userAnswers[i] = userAnswer;
  }

  time(&currentTime);
  elapsedSeconds = (int)difftime(currentTime, start_time); // Cast difftime to int

  printf("\nName: %s %s\n", firstName, lastName);
  printf("Signed in successfully. Time taken: %d seconds\n", elapsedSeconds);

  int score = calculateScore(questions, 50, userAnswers);
  printf("\nYour score: %d\n", score);

  return 0;
}
