class Solution{
	string compressBad(string str){
		string compressedString = "";
		int count;
		for(int i = 0; i < str.length(); i++){
			count++;
			if(i + 1 >= str.length() || str[i] != str[i + 1]){
				compressedString += str[i] + count;
				count = 0;
			}
		}
		return compressedString.length < str.length ? compressedString : str;
	}
};
