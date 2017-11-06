int values[5];

void setup() {
    Serial.begin(9600);
    pinMode(9, OUTPUT);
}

void sort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] > a[o+1]) {
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
                }
        }
    }
}

int median() {
    sort(values, 5);
    return values[2];
}

void loop() {
    for (int i = 0; i < 5; i++){
        values[i] = analogRead(A0);
    }

    Serial.println(median());
    tone(9, map(median(), 250, 1000, 500, 1500));
    delay(250);
    noTone(9);
    delay(250);
}
