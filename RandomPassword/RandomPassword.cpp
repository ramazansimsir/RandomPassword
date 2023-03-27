// RandomPassword.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <random>


using namespace std;

string special_character = "*+%&?!-";
string password = "";

void random_password_maker(int p_len,int upper,int lower,int special) {
    
    int num;
    int slen = special_character.size();
    int int_number = p_len - upper - lower - special;
    for (int i = 0; i < upper; i++) {
        num = 65 + (rand() % 26);
        password += char(num);
    }

    for (int i = 0; i < lower; i++) {
        num = 97 + (rand() % 26);
        password += char(num);
    }
    for (int i = 0; i < special; i++) {
        num = 1 + (rand() % slen);
        password += special_character[num];
    }
    for (int i = 0; i < int_number; i++) {
        num = 48 + (rand() % 10);
        password += char(num);
    }

    cout << password<<endl;
}

void mixed_password() {

    int len = password.size();
    char temp;
    int rand_index=0;

    for (int i = 0; i < (len/2)+2; i++) {
        rand_index = rand() % len;
        temp = password[rand_index];
        password[rand_index] = password[i];
        password[i] = temp;
    }
    cout << password<<endl;

}



int main()
{
    // First we need to password's length;
    int password_len=0;
    int upper_letter_number;
    int lower_letter_number;
    int num_number;
    int special_number;

    cout << " Please enter your password length password must be taller than 6 character" << endl;
    cin >> password_len;

    while (password_len < 8) {
        cout << " Your password is short ,password must be taller than 6 character " << endl;
        cin >> password_len;
    }

    cout << "password contains minimum 1 upper letter \n";
    cout << "password contains minimum 1 lower letter \n";
    cout << "password contains minimum 1 special charachter \n";
    cout << "How many upper letter does your password contain \n";
    cin >> upper_letter_number;
    cout << "How many upper letter does your password contain \n";
    cin >> lower_letter_number;
    cout << "How many special char does your password contain \n";
    cin >> special_number;


    while (upper_letter_number < 1 || lower_letter_number < 1 ||special_number<1 ||upper_letter_number + lower_letter_number+special_number >= password_len) {

        if (upper_letter_number < 1) {
            cout << "password contains minimum 1 upper letter \n";
            cout << "Try again \n";
            cin >> upper_letter_number;
        }
        if (lower_letter_number < 1) {
            cout << "password contains minimum 1 lower letter \n";
            cin >> lower_letter_number;
        }
        if (special_number < 1) {
            cout << "password contains minimum 1 special character \n";
            cin >> special_number;
        }
        if (upper_letter_number + lower_letter_number+special_number >= password_len) {
            cout << "your password is short  \n";
            cout << "your password len is " << password_len << " try again \n";
            cout << "How many upper letter does your password contain \n";
            cin >> upper_letter_number;
            cout << "How many upper letter does your password contain \n";
            cin >> lower_letter_number;
            cout << "How many special char does your password contain \n";
            cin >> special_number;
        }
    }

    random_password_maker(password_len, upper_letter_number, lower_letter_number,special_number);
    mixed_password();

}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
