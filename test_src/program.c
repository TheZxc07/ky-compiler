int main() {
    int X = 23;
    int Y = 7;
    int Z = 99;
    int result;

    while (X > 0) {
        result = X + Y;
        printf("Result: %d\n", result);
        X = X - 1;
    }

    result = Z + 1234;
    printf("Final Result: %d\n", result);

    return 0;
}
