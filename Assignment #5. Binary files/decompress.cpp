#include "decompress.h"

using namespace std;

void decompress(char* decodedName, char* encodedName) {

    string *result = new string;
    FILE *encoded;
    FILE *decoded;
    encoded = fopen(encodedName, "r+b");
    decoded = fopen(decodedName, "w+b");
    if (encoded == nullptr) {
        perror("Can`t open file");
    } else {

        char buffer[3];
        string buf_for_two;
        int *size_of_dict = new int;
        *size_of_dict = 1;
        int boc = 1; // bytes of code of phrase
        int counter_of_phrs = 0;
        phrase** dictionary = (phrase**)malloc(*size_of_dict * sizeof(phrase*));

        while(fread(buffer, sizeof(char), boc + 1, encoded) == boc + 1){

            if (counter_of_phrs == *size_of_dict) dictionary = resize(dictionary, size_of_dict);

            int phrase_num;
            if(boc == 2){

                int first = (int)buffer[0];
                int second = (int)buffer[1];
                buf_for_two = bitset<8>(first).to_string() + bitset<8>(second).to_string();

                phrase_num = bitset<16>(buf_for_two).to_ulong();
            } else {
                phrase_num = (int)buffer[0] + 127;
            }

            if (phrase_num == 0){

                if (counter_of_phrs < 65536){
                    dictionary[counter_of_phrs] = new phrase(buffer[boc], nullptr);
                    dictionary[counter_of_phrs++] -> get_phrase(result);
                } else {
                    dictionary[counter_of_phrs] = new phrase(buffer[boc], dictionary[phrase_num - 1]);
                    result -> push_back(buffer[boc]);
                }

            } else {
                if (counter_of_phrs < 65536){
                    dictionary[counter_of_phrs] = new phrase(buffer[boc], dictionary[phrase_num - 1]);
                    dictionary[counter_of_phrs++] -> get_phrase(result);
                } else {
                    dictionary[phrase_num - 1] -> get_phrase(result);
                    result -> push_back(buffer[boc]);
                }
            }

            if (counter_of_phrs == 256){
                boc = 2;
            }
        }

        for (int i = 0; i < result -> size(); i++){
            fwrite(&(*result)[i], sizeof(char), 1, decoded);
        }
        fclose(decoded);
        fclose(encoded);
    }
}

phrase::phrase(char ch, phrase* ph){
    curr = ch;
    prev = ph;
};

void phrase::get_phrase(string* str) {
    if (prev != nullptr) {
        prev->get_phrase(str);
    }
    str->push_back(curr);
}

phrase** resize(phrase** curr, int* curr_size){
    phrase** new_dict = (phrase**)malloc(*curr_size * 2 * sizeof(phrase*));
    for (int i = 0; i < *curr_size; i++){
        new_dict[i] = curr[i];
        curr[i] = nullptr;
    }
    (*curr_size) *= 2;
    delete [] curr;
    return new_dict;
}