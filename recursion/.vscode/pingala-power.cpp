int pingala_power(int a, int n) {
    if (n == 1) {
        return a;
    }
    int x = pingala_power(a, n / 2);
    if (n % 2 == 0) {
        return x * x;
    }
    return x * x * a;
}

int peasant_power(int a, int n) {
    if (n == 1) {
        return a;
    } else if (n % 2 == 0) {
        return peasant_power(a * a, n / 2);
    } else {
        return a * peasant_power(a * a, n / 2);
    }
}