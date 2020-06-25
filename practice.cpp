#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
	public :

	char data;
	TrieNode** children;
	bool isTerminal;

	TrieNode(char data)
	{
		this->data = data;
		children = new TrieNode*[26];
		isTerminal = false;
		for(int i = 0 ; i < 26;i++)
			children[i] = NULL;
	}


};


class Tries
{
	public:
		TrieNode* root;

		Tries()
		{
			root = new TrieNode('\0');
		}
	
	private:

		void insert(TrieNode* root , string word)
		{
			if(word.length() == 0)
			{
				root->isTerminal = true;
				return ;
			}

			int index = word[0] - 'a';
			TrieNode* child;
			if(root->children[index] != NULL)
			{
				
				child = root->children[index];
			}
			else
			{
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}

			insert(child , word.substr(1));
		}

		bool search(TrieNode* root , string word)
		{
			if(word.length() == 0)
			{
				if(root->isTerminal == true)
					return true;
				else
					return false;
			}

			int index = word[0] - 'a';
			if(root->children[index] == NULL)
				return false;
			else
			{
				TrieNode *child = root->children[index];
			
			return search(child , word.substr(1));
			}
		}

		void remove(TrieNode* root , string word)
		{
			if(word.length() == 0)
			{
				root->isTerminal = false;
				return;
			}

			int index = word[0] - 'a';
			TrieNode* child ;
			if(root->children[index] != NULL)
			{
				 child = root->children[index];

			}
			else
				return;

			remove(child , word.substr(1));

			if(child->isTerminal == false)
			{
				for(int i = 0 ; i < 26 ; i++)
				{
					if(child->children[i] != NULL)
						return;
				}

				delete child;
				root->children[index] = NULL;

			}

		}


	public:
		void insert(string word)
		{
			insert(root,word);
		}

		bool search(string word)
		{
			return search(root , word);
		}
		void remove(string word)
		{
			remove(root , word);
		}
};


int main()
{

	Tries t;
	t.insert("banana");
	t.insert("donut");
	t.insert("do");
	t.insert("double");
	t.insert("racket");
	t.insert("reckless");
	t.insert("banal");

	cout<<t.search("racket")<<endl;
	cout<<t.search("ball")<<endl;

	t.remove("racket");

	cout<<t.search("racket")<<endl;

	
	return 0;
}