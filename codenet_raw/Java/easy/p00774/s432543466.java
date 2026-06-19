import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int height;
        while((height = scn.nextInt()) > 0) {
            Puzzle puzzle = new Puzzle(height);
            puzzle.proc();
            System.out.println(puzzle.showScore());
        }
    }
}

class Puzzle {
    int score;
    int[][] numbers;

    private static int WIDTH = 5;
    private static int VANISH = 3;

    Puzzle(int height) {
        Scanner scn = new Scanner(System.in);

        score = 0;
        numbers = new int[height][WIDTH];

        for(int i = 0; i < height; i++) {
            for(int j = 0; j < WIDTH; j++) {
                numbers[i][j] = scn.nextInt();
            }
        }
    }

    int showScore() {
        return score;
    }

    void proc() {
        int lines;
        while((lines = vanishPhase()) > 0) {
            dropPhase(lines);
        }
    }

    private int vanishPhase() {
        int lines = 0;
        for(int i = 0; i < numbers.length; i++) {
            for(int j = 0; j <= WIDTH - VANISH; j++) {
                int base = numbers[i][j];
                if(base > 0) {
                    int count = 1;
                    while(j + count < WIDTH && base == numbers[i][j + count]) {
                        count++;
                    }
                    if(count >= VANISH) {
                        score += base * count;
                        while(count-- > 0) {
                            numbers[i][j + count] = 0;
                        }
                        lines++;
                        break;
                    }
                }
            }
        }
        return lines;
    }

    private void dropPhase(int lines) {
        while(lines-- > 0) {
            for(int i = ~-numbers.length; i > 0; i--) {
                for(int j = 0; j < WIDTH; j++) {
                    if(numbers[i][j] == 0) {
                        numbers[i][j]   ^= numbers[~-i][j];
                        numbers[~-i][j] ^= numbers[i][j];
                        numbers[i][j]   ^= numbers[~-i][j];
                    }
                }
            }
        }
    }
}