#include <iostream>
#include <Windows.h>
#include <string>

HANDLE Th1, Th2, Th3, ThLoader;

void increment() {
    long num = 0;
    int i = 0;
    DWORD thId = GetCurrentThreadId();
    DWORD time1 = GetTickCount64();
    while (true) {
        
        num++;
        i++;
        DWORD time2 = GetTickCount64();
        DWORD time = time2 - time1;
        if (time >= 1000) {
            std::cout << "Поток ID: " << thId << " - итерации: " << i << " - Инкремент: " << num << std::endl;
            i = 0;
            time1 = GetTickCount64();
        }
        
        
    }
}

void fibonacci() {
    long a = 0, b = 1;
    int i = 0;
    DWORD thId = GetCurrentThreadId();
    DWORD time1 = GetTickCount64();
    while (true) {
        int next = a + b;
        a = b;
        b = next;
        i++;
        DWORD time2 = GetTickCount64();
        DWORD time = time2 - time1;
        if (time >= 1000) {
            std::cout << "Поток ID: " << thId << " - итерации: " << i << " - Фибоначчи: " << a << std::endl;
            i = 0;
            time1 = GetTickCount64();
        }
    }
}

void factorial() {
    long n = 0;
    long fact = 1;
    int i = 0;
    DWORD thId = GetCurrentThreadId();
    DWORD time1 = GetTickCount64();
    while (true) {
        if (n == 0 || n == 1) {
            fact = 1;
        }
        else {
            fact = 1;
            for (int i = 2; i <= n; i++) {
                fact *= i;
            }
        }
        
        n++;
        i++;
        DWORD time2 = GetTickCount64();
        DWORD time = time2 - time1;
        if (time >= 1000) {
            std::cout << "Поток ID: " << thId << " - итерации: " << i << " - Факториал: " << fact << std::endl;
            i = 0;
            time1 = GetTickCount64();
        }
        
    }
}

void Loader() {
    std::cout << "Нагрузчик запущен" << std::endl;
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
    std::cout << "Максимальный приоритет" << std::endl;
    long l = 0;
    int j = 0;
    DWORD time1 = GetTickCount64();
    for (int i = 0; i < 10000; i++)
    {
        std::cout << "Нагрузчик приоритет максимальный - количество итерации - " << j << std::endl;
        l++;
        j++;
        DWORD time2 = GetTickCount64();
        DWORD time = time2 - time1;
        if (time >= 1000) {
            j = 0;
            time1 = GetTickCount64();
        }
    }
    std::cout << "Нагрузчик приоритет нормальный" << std::endl;
    SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_NORMAL);
    Sleep(3000);
}

int main() {
    setlocale(LC_ALL, "ru");

    Th1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)increment, NULL, 0, NULL);
    Th2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)fibonacci, NULL, 0, NULL);
    Th3 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)factorial, NULL, 0, NULL);

    SetThreadPriority(Th1, THREAD_PRIORITY_IDLE);
    SetThreadPriority(Th2, THREAD_PRIORITY_NORMAL);
    SetThreadPriority(Th3, THREAD_PRIORITY_HIGHEST);
    system("cls");
    while (true)
    {
        std::cout << "1. Поток 1 - низкий приоритет" << std::endl;
        std::cout << "2. Поток 1 - нормальный приоритет" << std::endl;
        std::cout << "3. Поток 1 - высокий приоритет" << std::endl;
        std::cout << "4. Поток 1 - фоновый приоритет" << std::endl;

        std::cout << "5. Поток 2 - низкий приоритет" << std::endl;
        std::cout << "6. Поток 2 - нормальный приоритет" << std::endl;
        std::cout << "7. Поток 2 - высокий приоритет" << std::endl;
        std::cout << "8. Поток 2 - фоновый приоритет" << std::endl;

        std::cout << "9. Поток 3 - низкий приоритет" << std::endl;
        std::cout << "10. Поток 3 - нормальный приоритет" << std::endl;
        std::cout << "11. Поток 3 - высокий приоритет" << std::endl;
        std::cout << "12. Поток 3 - фоновый приоритет" << std::endl;

        std::cout << "13. Поток нагрузчик" << std::endl;
        std::cout << "0. Выход" << std::endl;

        int user;
        std::cin >> user;
        switch (user) {
        case 1:
            SetThreadPriority(Th1, THREAD_PRIORITY_LOWEST);
            std::cout << "Потоку 1 приоритет низкий" << std::endl;
            break;
        case 2:
            SetThreadPriority(Th1, THREAD_PRIORITY_NORMAL);
            std::cout << "Потоку 1 приоритет нормальный" << std::endl;
            break;
        case 3:
            SetThreadPriority(Th1, THREAD_PRIORITY_HIGHEST);
            std::cout << "Потоку 1 приоритет высокий" << std::endl;
            break;
        case 4:
            SetThreadPriority(Th1, THREAD_PRIORITY_IDLE);
            std::cout << "Потоку 1 приоритет фоновый" << std::endl;
            break;
        case 5:
            SetThreadPriority(Th2, THREAD_PRIORITY_LOWEST);
            std::cout << "Потоку 2 приоритет низкий" << std::endl;
            break;
        case 6:
            SetThreadPriority(Th2, THREAD_PRIORITY_NORMAL);
            std::cout << "Потоку 2 приоритет нормальный" << std::endl;
            break;
        case 7:
            SetThreadPriority(Th2, THREAD_PRIORITY_HIGHEST);
            std::cout << "Потоку 2 приоритет высокий" << std::endl;
            break;
        case 8:
            SetThreadPriority(Th2, THREAD_PRIORITY_IDLE);
            std::cout << "Потоку 2 приоритет фоновый" << std::endl;
            break;
        case 9:
            SetThreadPriority(Th3, THREAD_PRIORITY_LOWEST);
            std::cout << "Потоку 3 приоритет низкий" << std::endl;
            break;
        case 10:
            SetThreadPriority(Th3, THREAD_PRIORITY_NORMAL);
            std::cout << "Потоку 3 приоритет нормальный" << std::endl;
            break;
        case 11:
            SetThreadPriority(Th3, THREAD_PRIORITY_HIGHEST);
            std::cout << "Потоку 3 приоритет высокий" << std::endl;
            break;
        case 12:
            SetThreadPriority(Th3, THREAD_PRIORITY_IDLE);
            std::cout << "Потоку 3 приоритет фоновый" << std::endl;
            break;
        case 13:
            ThLoader = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Loader, NULL, 0, NULL);
            break;
        case 0:
            TerminateThread(Th1, 0);
            TerminateThread(Th2, 0);
            TerminateThread(Th3, 0);
            TerminateThread(ThLoader, 0);
            return 0;
        default:
            std::cout << "Неверно выбранное действие!" << std::endl;
            break;
        }

    }

    WaitForSingleObject(Th1, INFINITE);
    WaitForSingleObject(Th2, INFINITE);
    WaitForSingleObject(Th3, INFINITE);

    CloseHandle(Th1);
    CloseHandle(Th2);
    CloseHandle(Th3);

    return 0;
}
