class Solution{
public:	
	bool isUniqueChars(string str){
		
		if(str.length() > 256) return false;
		
		bool char_set[256] = {false};
		
		for(int i = 0; i < str.length(); i++){
			int val = str[i];
			if(char_set[val]) return false;
			char_set[val] = true;
		}
		return true;
	}
};
