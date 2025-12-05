import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        String filePath = "../assets/input.txt";
        char[][] map = readMapFromFile(filePath);
        int sum = 0;
        for (int row = 0; row < map.length; row++) {
            for (int col = 0; col < map[0].length; col++) {
                sum += is_valid(map, row, col);
            }
        }
        System.out.println(sum);
    }

    private static char[][] readMapFromFile(String filePath) {
        try (BufferedReader br = new BufferedReader(new FileReader(filePath))) {
            List<String> lines = br.lines().toList();
            int rows = lines.size();
            int cols = lines.get(0).length();
            char[][] map = new char[rows][cols];
            for (int i = 0; i < rows; i++) {
                map[i] = lines.get(i).toCharArray();
            }
            return map;
        } catch (IOException e) {
            e.printStackTrace();
            return new char[0][0];
        }
    }

    private static int is_valid(char[][] map, int row, int col) {
        if (map[row][col] == '@') {
            int[] directions = {-1, 0, 1};
            int cnt_a = 0;
            for (int dr : directions) {
                for (int dc : directions) {
                    if (dr == 0 && dc == 0) {
                        continue;
                    }
                    int newRow = row + dr;
                    int newCol = col + dc;
                    // Check bounds
                    if (newRow >= 0 && newRow < map.length && newCol >= 0 && newCol < map[0].length) {
                        cnt_a += (map[newRow][newCol] == '@') ? 1 : 0;
                    }
                }
            }
            return cnt_a < 4 ? 1 : 0;
        }
        return 0;
    }
}

// Answer: 1428
