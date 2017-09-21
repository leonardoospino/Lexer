#ifndef LEXER_H
#define LEXER_H

void menu(){
	system("CLS");
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
	cout<<"+\t\t\tAUTOMATA\t\t\t\t   +\n";
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n";
	cout<<"Digite un sentencia: ";
}

class Lexer {
    private:
		int ERROR = -1;
	    int ADD = 1;
	    int SUBTRACT = 2;
	    int ASSIGN = 3;
	    int INTEGER = 5;
	    int LETTERS = 7;
	    int PRINT = 12;
    	string word;
    	int mark=-1;
    public:
	    Lexer(string word){
			this->word=word;
		}
		
		string getWord(){
			return this->word;
		}
		
		int getMark(){
			return this->mark;
		}
		
		void decrementMark(){
			this->mark--;
		}
		
	    char getChar(){
	    	mark++;
	    	return this->word[mark];
	    }
	    
	    int state_0(){
	        char c = getChar();
	        switch(c){
	            case '+': return state_1();
	            case '-': return state_2();
	            case '=': return state_3();
	            case 'p':
	                return state_8();
	            default:
	            	if(c>='1' && c<='9')
	            		return state_4();
	                else if((c>='a' && c<='z') || (c>='A' && c<='Z'))
	                    return state_6();
	                return ERROR;
	        }
	    }
	    
	    int state_1(){
	        return ADD;
	    }
	    
	    int state_2(){
	        return SUBTRACT;
	    }
	    
	    int state_3(){
	        return ASSIGN;
	    }
	    
	    int state_4(){
	        char c = getChar();
	        switch(c){
	            case '+': 
	            case '-':
	            case '=':
	                return state_5();
	            default:
	                if(c>='0' && c<='9')
	                	return state_4();
					else if((c>='a' && c<='z') || (c>='A' && c<='Z') )
	                    return state_5();
	                return ERROR;
	        }
	    }
	    
	    int state_5(){
	        return INTEGER;
	    }
	    
	    int state_6(){
	        char c = getChar();
	        if((c=='+' || c=='-' || c=='=') || (c>='0' && c<='9'))
	        	return state_7();
	        else if((c>='a' && c<='z') || (c>='A' && c<='Z') )
                return state_6();
            return ERROR;
	    }
	    
	    int state_7(){
	        return LETTERS;
	    }
	    
	    int state_8(){
	        char c = getChar();
	        if((c=='+' || c=='-' || c=='=') || (c>='0' && c<='0'))
	        	return state_13();
	        else if(c=='r')
	        	return state_9();
	        else if((c>='a' && c<='z') || (c>='A' && c<='Z') )
	            return state_6();
	        return ERROR;
	    }
	    
	    int state_9(){
	    	char c = getChar();
	    	if((c=='+' || c=='-' || c=='=') || (c>='0' && c<='0'))
	        	return state_13();
	        else if(c=='i')
	        	return state_10();
	        else if((c>='a' && c<='z') || (c>='A' && c<='Z'))
	            return state_6();
	        return ERROR;
	    }
	    
	    int state_10(){
	        char c = getChar();
	        if((c=='+' || c=='-' || c=='=') || (c>='0' && c<='0'))
	        	return state_13();
	        else if(c=='n')
	        	return state_11();
	        else if((c>='a' && c<='z') || (c>='A' && c<='Z'))
	            return state_6();
	        return ERROR;
	    }
	    
	    int state_11(){
	    	char c = getChar();
	        if((c=='+' || c=='-' || c=='=') || (c>='0' && c<='0'))
	        	return state_13();
	        else if(c=='t')
	        	return state_12();
	        else if((c>='a' && c<='z') || (c>='A' && c<='Z'))
	            return state_6();
	        return ERROR;
	    }
	    
	    int state_12(){
	        return PRINT;  
	    }
	    
	    int state_13(){
	        return LETTERS;
	    }
};

#endif