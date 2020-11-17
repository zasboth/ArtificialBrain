/*
 * Serializable.h
 *
 *  Created on: Aug 6, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_SERIALIZABLE_H_
#define TERNARYLOGIC_SERIALIZABLE_H_
#include <string>
#include <vector>

using namespace std;


class Serializable
{
public:
	virtual ~Serializable(){}

	virtual string save() = 0;
	virtual void load(string& s) = 0;
	virtual int version() = 0;
};


template <typename T>
static inline string vector_to_json(vector<T> &v, string f(T v)){
	string result("[");
	for (size_t i = 0; i < v.size(); ++i)
	{
		result += f(v[i]);
		if (i < v.size()-1) {
			result += ", ";
		}
	}
	result += "]";
	return result;
}

template <typename T>
static inline vector<T> json_to_vector(string s, T f(string v)){
	vector<T> result;
	s.pop_back();
	s.erase(0);
	string buffer;
	for(auto c : s){
		if(c == ','){
			result.push_back(f(buffer));
			buffer.clear();
		}else{
			buffer.push_back(c);
		}
	}
	result.push_back(f(buffer));
	return result;
}

#endif /* TERNARYLOGIC_SERIALIZABLE_H_ */
