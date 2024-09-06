int nwd(int a, int b) {
    int reszta;
    while(b!=0) {
        reszta = a % b;
        a = b;
        b = reszta;
    }

    return a;
}