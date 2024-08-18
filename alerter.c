#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 150.0) {
        return 500;
    } else {
        return 200;
    }
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment the failure count if the alert fails
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    assert(alertFailureCount == 2); 
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
