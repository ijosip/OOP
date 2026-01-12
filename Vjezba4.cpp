#include<iostream>
#include<vector>
#include <algorithm>
#include<cmath>

using namespace std;

void input_vector(vector<int>& v)
{
	int num;
	cout << "Unesi broj" << endl;

	while (true)
	{
		cin >> x;

		if (x == 0) break;
		v.push_back(x);
	}
	
}

void print_vector(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++) {
		cout <<v[i];
		if ((i+1) < v.size())
		{
			cout << ",";
		}
		
	}

}


void fix_spaces(string& text)
{

	auto prva = unique(text.begin(), text.end(), [](char a, char b) {return a == ' ' && b == ' '; });
	text.erase(prva, text.end());


	size_t pos = 0;
	while ((pos = text.find(" ,", pos)) != std::string::npos) {
		text.erase(pos, 1); 
	}

	pos = 0;
	while ((pos = text.find(" .", pos)) != std::string::npos) {
		text.erase(pos, 1); 
	}

	
	pos = 0;
	while ((pos = text.find(',', pos)) != std::string::npos) {
		if (pos + 1 < text.length() && text[pos + 1] != ' ') {
			text.insert(pos + 1, " ");
		}
		pos++;
	}

	
	pos = 0;
	while ((pos = text.find('.', pos)) != std::string::npos) {
		if (pos + 1 < text.length() && text[pos + 1] != ' ') {
			text.insert(pos + 1, " ");
		}
		pos++;
	}

	if (!text.empty() && text[0] == ' ') {
		text.erase(0, 1);
	}
	if (!text.empty() && text[text.length() - 1] == ' ') {
		text.erase(text.length() - 1, 1);
	}

}


string word_to_pig_latin(const string& word)
{
	if (word.empty())
		return "";

	char first = tolower(word[0]); 
	string vowels = "aeiou";

	
	if (vowels.find(first) != string::npos) {
		return word + "hay";
	}
	else {
		return word.substr(1) + word[0] + "ay";
	}
}


void reverse_strings(vector<string>& words) {
	for (auto& word : words) {
		reverse(word.begin(), word.end());
	}
}

int main()
{
	vector<int>vect;

	input_vector(vect);

	cout << "Vektor glasi:" << endl;;
	print_vector(vect);
	cout << endl;

	vector<int>jedinstveni;

	for (const auto& el:vect) 
	{
		if (find(jedinstveni.begin(), jedinstveni.end(), el) == jedinstveni.end()) {
			jedinstveni.push_back(el);
		}
	}
	cout << "Jedinstveni elementi: ";
	print_vector(jedinstveni);
	cout << endl;

	sort(jedinstveni.begin(), jedinstveni.end(),[](int a, int b)
	{
		return abs(a) < abs(b);
	});
	

string text;
cout << "Unesi recenicu: " << endl;
cin.ignore();
getline(cin, text);

fix_spaces(text);

cout << "Novi text glasi:" << text << endl;


cout << word_to_pig_latin("apple") << endl; 
cout << word_to_pig_latin("hello") << endl; 
cout << word_to_pig_latin("Table") << endl; 


vector<string> words = { "hello", "world", "c++", "programming", "algorithm" };

reverse_strings(words);

cout << "Nakon okretanja:" << endl;
for (const auto& word : words) {
	cout << word << " ";
}
cout << endl;

	return 0;

}
