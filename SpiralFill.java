public class Main {
    public static void main(String[] args) {
        int cols = 6, rows = 5;
        int[][] arr = new int[rows][cols];

        for (int i = 0, c = 1, m = 0; i <= cols / 2; i++, m++) {
            for (int j = m; j < cols - m; j++) arr[i][j] = c++;
            for (int j = m + 1; j < rows - m - 1; j++) arr[j][cols - m - 1] = c++;
            for (int j = cols - m - 1; c <= rows * cols && j >= m; j--) arr[rows - i - 1][j] = c++;
            for (int j = rows - m - 2; j > m; j--) arr[j][i] = c++;
        }

        for (int[] ints : arr) {
            for (int anInt : ints) System.out.printf("%2d ", anInt);
            System.out.println();
        }
    }
}

// Output
// 1  2  3  4  5  6 
// 18 19 20 21 22  7 
// 17 28 29 30 23  8 
// 16 27 26 25 24  9 
// 15 14 13 12 11 10 