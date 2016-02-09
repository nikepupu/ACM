//#include <boost/algorithm/string.hpp>
#include <unordered_set>
#include <iostream>
#include <cctype>
#include <string>
#include <cstring> 
#include <vector>
#include <queue>
#include <fstream>
#include <sstream>

#define DEBUG 0
#define NUM_CHAR 26

//using namespace boost::algorithm;
using namespace std;
 
typedef struct queueElements {
	char* word;
	string suffix;
}queueElements;

class trie {
    private:
        struct node {
            char  character;       
            bool  eow;             
            node* edge[NUM_CHAR];        
        }*root;                    
 	 
    public:
        trie();                        
        ~trie();                      
        void insertWord(char *); 
        bool searchWord(char *); 
	bool isSinglePrefixWord(char* );    
	vector<string> findPrefixes(char *);
	void solveChallenge();
        void display(); 
	void print(node* , string);
};

trie::trie() {
    root = new node();
    root->character = '\0';
    root->eow = false;
    for(int i=0;i<NUM_CHAR;i++) {
        root->edge[i] = NULL;
    }
}

trie::~trie() {

}
 
void trie::insertWord(char* s) {
	static int count  = 0;
	count++;
	string tmp = s;
	//cout<< " count : "<<count <<" | s: " << tmp<<endl ;
	node *t = root;
	while(*s != '\0') {
	        int c = toupper(*s) - 'A';
		if(c<0 || c>25) break;
		if(t->edge[c] == NULL) {
		    if(count == 1372) {
			//cout<< "c: " <<c<< "char: "<<*s<<endl;
		    }	
		    node* n = new node();
		    n->character = *s;
		    n->eow = false;
		    for(int i=0;i<NUM_CHAR;i++) {
			n->edge[i] = NULL;
		    }
		    t->edge[c] = n;
		    t = n;
		}
		else {
		    t = t->edge[c];
		}
		s++;
	
	}
	if(t!=NULL)
	t->eow = true;
}

bool trie::searchWord(char* s) {
	node *t = root;
	while(*s != '\0') {
		int c = toupper(*s) - 'A';
		if(c<0 || c>25) break;
		
        	if(t->edge[c] == NULL) {
	            return false;
        	}
       		else {
	            t = t->edge[c];
        	}
        	s++;
    	}
	
	return t->eow;
}

bool trie::isSinglePrefixWord(char* s) {
	node *t = root;
	while(*s != '\0') {
		int c = toupper(*s) - 'A';
		if(c<0 || c>25) break;
		
        	if(t->eow) {
	            return false;
        	}
       		else {
	            t = t->edge[c];
        	}
        	s++;
    	}
	return true;	
}
vector<string> trie:: findPrefixes(char* s) {
	node *t = root;
	string p = "";
	vector<string> prefixes;
	while(*s != '\0') {
		int c = toupper(*s) - 'A';
		if(c<0 || c>25) break;
	        if(t->edge[c] == NULL) {
			return prefixes;
		}
		p += t->edge[c]->character;
		t = t->edge[c];
		if(t->eow) prefixes.push_back(p);
		s++;
	}	
	return prefixes;
}

void trie::print(node* t, string prefix) {
    if (t->eow)
        cout << prefix << endl;
    for (int i = 0; i <NUM_CHAR; ++i) {
        if (t->edge[i] != NULL) {
            string currentString = prefix + t->edge[i]->character;
            print(t->edge[i], currentString);
        }
    }
}

void trie::display() {
	string s = "";	
	print(root, s);
}
 
int main(int argc, char **argv) {
	trie mytrie;
	ifstream inputFile;
	inputFile.open("wordsforproblem.txt");
	//inputFile.open("test.txt");
	queue<queueElements> q;
	string buffer = "";
	while(!inputFile.eof()) {
		getline(inputFile, buffer);
		//cout<<"Buffer: " <<buffer <<endl;
		if(!buffer.empty()) {
			char* c = strdup(buffer.c_str());
			vector<string> prefixes = mytrie.findPrefixes(c);	
			queueElements e;				
			e.word = c;
			string tmp = e.word;
			for(int i=0; i<prefixes.size(); i++) {
				e.suffix = tmp.substr(prefixes[i].length()); 
				q.push(e);
			}
			mytrie.insertWord(c);
			buffer = "";
		}
	}
	inputFile.close();	

	string longestWord;
	string secondlongestWord;
	int longestLength = 0;
	int secondLongestLength = 0;
	int concatWords = 0;
	bool set = false;

	unordered_set <string> concatSet; 
	while(!q.empty()) {
		queueElements e = q.front();
		q.pop();
		string s = e.word; 
		char* c = strdup(e.suffix.c_str());
		if(mytrie.searchWord(c) && !mytrie.isSinglePrefixWord(e.word)) {
			//cout<<e.word<<endl;
			if(concatSet.count(s)<1) {
				concatSet.insert(s);	
				concatWords++;
			}
			if(s.length()>=longestLength) {
				if(set) {
					secondLongestLength = longestLength;
					secondlongestWord = longestWord;
				}
				else {
					set = !set;
				}
				longestLength = s.length();
				longestWord = s;
			}

		}
		else {
			vector<string> prefixes = mytrie.findPrefixes(c);
			if(prefixes.size()>0) {
				for(int i=0; i<prefixes.size(); i++) {
					queueElements t;
					t.word = e.word;
					t.suffix = e.suffix.substr(prefixes[i].length());
					q.push(t);
				}
			}	
		}
	}

	cout<< "Longest Concatenated Word   : " <<longestWord<< endl;
	stringstream trimmer;
	trimmer << longestWord;
	trimmer >> longestWord;	
	cout<< "Longest Concatenated Length : " <<longestWord.length()<<endl;
	cout<< "2nd Longest Concatenated Word   : " <<secondlongestWord<< endl;
	trimmer << secondlongestWord;
	trimmer >> secondlongestWord;	
	cout<< "2nd Longest Concatenated Length : " <<secondlongestWord.length()<<endl;
	cout<< "Total Concatenated Words   : " <<concatWords<<endl;
}
