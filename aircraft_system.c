#include <stdio.h>

typedef struct {
    int temperature;
    int pressure;
    int vibration;
} SensorData;

SensorData collectSensorData() {
    SensorData data;
    // 예시: 실제 센서에서 데이터를 읽어올 수 있는 코드 필요
    data.temperature = 25; // 가상의 온도 데이터
    data.pressure = 1013;  // 가상의 기압 데이터
    data.vibration = 5;    // 가상의 진동 데이터

    return data;
}
typedef enum {
    NORMAL,
    WARNING,
    CRITICAL
} Status;

Status analyzeData(SensorData data) {
    if (data.temperature > 50) {
        return CRITICAL;
    }
    if (data.pressure < 1000 || data.pressure > 1020) {
        return WARNING;
    }
    if (data.vibration > 10) {
        return CRITICAL;
    }
    return NORMAL;
}
void recordData(SensorData data, Status status) {
    FILE *file = fopen("log.txt", "a");
    if (file != NULL) {
        fprintf(file, "Temperature: %d, Pressure: %d, Vibration: %d, Status: %d\n",
                data.temperature, data.pressure, data.vibration, status);
        fclose(file);
    }
}
void notify(Status status) {
    if (status == WARNING) {
        printf("경고: 부품 검사가 필요합니다.\n");
    } else if (status == CRITICAL) {
        printf("긴급: 즉시 부품 교체가 필요합니다.\n");
    }
}
int main() {
    SensorData data = collectSensorData();
    Status status = analyzeData(data);
    recordData(data, status);
    notify(status);
    
    return 0;
}
