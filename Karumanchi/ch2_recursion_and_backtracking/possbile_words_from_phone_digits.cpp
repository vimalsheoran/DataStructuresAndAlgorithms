#include <iostream>
#include <cstring>

using namespace std;

void determine_phone_word(int *key_seq, int seq_len, string curr_word, int seq_index) {
	if (seq_index == seq_len) {
		cout << curr_word << endl;
		return;
	}
	if (key_seq[seq_index] == 2) {
		determine_phone_word(key_seq, seq_len, curr_word+"a", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"b", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"c", seq_index+1);
	} else if (key_seq[seq_index] == 3) {
		determine_phone_word(key_seq, seq_len, curr_word+"d", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"e", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"f", seq_index+1);
	} else if (key_seq[seq_index] == 4) {
		determine_phone_word(key_seq, seq_len, curr_word+"g", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"h", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"i", seq_index+1);
	} else if (key_seq[seq_index] == 5) {
		determine_phone_word(key_seq, seq_len, curr_word+"j", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"k", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"l", seq_index+1);
	} else if (key_seq[seq_index] == 6) {
		determine_phone_word(key_seq, seq_len, curr_word+"m", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"n", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"o", seq_index+1);
	} else if (key_seq[seq_index] == 7) {
		determine_phone_word(key_seq, seq_len, curr_word+"p", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"q", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"r", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"s", seq_index+1);
	} else if (key_seq[seq_index] == 8) {
		determine_phone_word(key_seq, seq_len, curr_word+"t", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"u", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"v", seq_index+1);
	} else if (key_seq[seq_index] == 9) {
		determine_phone_word(key_seq, seq_len, curr_word+"w", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"x", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"y", seq_index+1);
		determine_phone_word(key_seq, seq_len, curr_word+"z", seq_index+1);
	} else {
		determine_phone_word(key_seq, seq_len, curr_word, seq_index+1);		
	}
}

int main () {
	int arr[3] = {2, 3, 4};
	determine_phone_word(arr, 3, "", 0);
}