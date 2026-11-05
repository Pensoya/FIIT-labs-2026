#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <locale.h>
#include <unistd.h>



#define N 20



const char names[N][32] = {"Молоко", "Хлеб", "Вода", "Масло", "Кружка", "Морковь 1кг", "Блокнот", "Ключ активации Windows", "Клавиатура", "Пельмени", "Картошка 1кг", "Огурцы 1кг", "Сапог", "Антивирус Kaspersky", "Моющее средство Fairy", "Бассейн", "GTA6 для PS5", "Кровать", "Кресло", "Рюкзак"};
const int prices[N] = {90, 55, 50, 165, 200, 60, 70, 14000, 7000, 250, 40, 90, 300, 2990, 200, 8500, 10990, 19000, 11000, 2500};
const char discounts[N][10] = {"10%", "5%", "15%", "20%", "25%", "12%", "8%", "3%", "7%", "20%", "10%", "15%", "30%", "40%", "10%", "5%", "2%", "25%", "20%", "35%"};
const float discountsN[N] = {0.1, 0.05, 0.15, 0.2, 0.25, 0.12, 0.08, 0.03, 0.07, 0.2, 0.1, 0.15, 0.3, 0.4, 0.1, 0.05, 0.02, 0.25, 0.2, 0.35};



void sleepdiscount() {
    printf("Применяем скидки.\n");
    sleep(1);
    printf("Применяем бонусы..\n");
    sleep(1);
    printf("Готово!\n");
    sleep(1);
}

void print_1d(int *a, int n) {
    for (int i = 0; i<n; i++) {
        printf("%d", a[i]);
    }
}

void print_tovar() {
    printf("Выберите товар:\n Молоко - 1001\n Хлеб - 1002\n Вода - 1003\n Масло - 1004\n Кружка - 1005\n Морковь 1кг - 1006\n Блокнот - 1007\n Ключ активации Windows - 1008\n Клавиатура - 1009\n Пельмени - 1010\n Картошка 1кг - 1011\n Огурцы 1кг  - 1012\n Сапог - 1013\n Антивирус Kaspersky - 1014\n Моющее средство Fairy - 1015\n Бассейн - 1016\n GTA6 для PS5 - 1017\n Кровать - 1018\n Кресло - 1019\n Рюкзак - 1020\n");
}



int main() {
    float all_buyN, all_discountsN;
    int menu;
    int finish = 0;
    setlocale(LC_ALL, "Russian");
    int all_in[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    while (finish == 0) {
        printf("\nВыберите опцию: \n 1 - Выбрать товар\n 2 - Рассчитать итоговую сумму к оплате\n");
        scanf("%d", &menu);
        switch (menu) {
            case 1: {
                int tovar, ans;
                print_tovar();
                scanf("%d", &tovar);
                int number = ((int) tovar) - 1001;
                if (number < 0 || number >= N) {
                    printf("Нет такого товара!\n");
                    break;
                }
                printf("Вы выбрали - %s, стоимость - %d, скидка - %s. Хотите добавить в чек?(1 - Да, 2 - Нет)\n", names[number], prices[number], discounts[number]);
                scanf("%d", &ans);
                if (ans == 1) {
                    all_in[number]++;
                    printf("Товар добавлен в чек!\n");
                } else if (ans == 2) {
                    continue;
                } else {
                    printf("Ошибка!\n");
                }
                break;
            }
            case 2:
                finish = 1;
                break;
            default:
                printf("Нет такой опции!\n");
                break;
        }
        float all_buy = 0.0;
        float all_discounts = 0.0;
        printf("\n----------------------------------------------\n Чек:\n----------------------------------------------\n");
        for (int i = 0; i<N; i++) {
            if (all_in[i] != 0) {
                printf("%s – стоимость за единицу %d руб. – количество %d шт. – общая стоимость за товар %d руб.\n", names[i], prices[i], all_in[i], all_in[i]*prices[i]);
                all_buy += all_in[i]*prices[i];
                all_discounts += all_in[i]*prices[i]*discountsN[i];
            }
        }
        printf("----------------------------------------------\n");
        printf("Общая стоимость товаров - %.2f, Суммарная скидка - %.2f, Итоговая сумма - %.2f\n ----------------------------------------------\n", all_buy, all_discounts, all_buy - all_discounts);
        all_buyN = all_buy;
        all_discountsN = all_discounts;
    }
    sleepdiscount();
    printf("----------------------------------------------\n");
    printf("Сумма к оплате: %.2f\n", all_buyN - all_discountsN);
    return 0;
}
