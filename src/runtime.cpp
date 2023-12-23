#include <iostream>
#include <dlfcn.h>

int main(){
    std::cout << "'0' - переключение реализации контрактов (по умолчанию 1 реализация). " << "\n"
    << "'1' - вызов функции подсчёта НОД для двух натуральных чисел." << "\n"
    << "'2' - вызов функции подсчета количества простых чисел на отрезке [A, B]" << "\n"
    << "'-1' - окончание работы программы." << "\n" << "\n"
    << "Введите номер команды: ";

    int num;
    std::cin >> num;

    int lib = 1;
    auto handle = dlopen("./liblib1.so", RTLD_LAZY);

    char* error;
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }

    int (*GCF)(int, int);
    GCF = reinterpret_cast<decltype(GCF)>(dlsym(handle, "GCF"));
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }

    int (*prime)(int, int);
    prime = reinterpret_cast<decltype(prime)>(dlsym(handle, "PrimeCount"));
    error = dlerror();
    if (error)
    {
        std::cerr << error << std::endl;
        return 1;
    }

    while (num != -1){
        switch (num){

            case 0:
                dlclose(handle);
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                switch (lib){
                    
                    case 1:
                        std::cout << "Переключено на реализацию 2. " << "\n" << "\n";
                        lib = 2;
                        handle = dlopen("./liblib2.so", RTLD_LAZY);
                        break;

                    case 2:
                        std::cout << "Переключено на реализацию 1. " << "\n" << "\n";
                        lib = 1;
                        handle = dlopen("./liblib1.so", RTLD_LAZY);
                        break;
                }

                char* error;
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                GCF = reinterpret_cast<decltype(GCF)>(dlsym(handle, "GCF"));
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                prime = reinterpret_cast<decltype(prime)>(dlsym(handle, "PrimeCount"));
                error = dlerror();
                if (error)
                {
                    std::cerr << error << std::endl;
                    return 1;
            }

                std::cout << "Введите номер команды: ";
                std::cin >> num;
                break;

            case 1:
                int a, b;
                std::cout << "Введите два натуральных числа: ";
                std::cin >> a >> b;

                std::cout << "НОД(" << a << "," << b << ") = " << GCF(a, b) << "\n" << "\n"
                << "Введите номер команды: ";
                std::cin >> num;
                break;

            case 2:
                int A, B;
                std::cout << "Введите концы отрезка A и B: ";
                std::cin >> A >> B;

                std::cout << "Количество простых чисел на отрезке [A, B]: " << prime(A, B) << "\n" << "\n"
                << "Введите номер команды: ";

                std::cin >> num;
                break;

            default:
                std::cout << "Команды с таким номером нет." << "\n";
                return -1;
        }
    }

    dlclose(handle);
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }
    return 0;
}