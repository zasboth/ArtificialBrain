/*
 * Serializable.h
 *
 *  Created on: Aug 6, 2020
 *      Author: zsolt
 */

#ifndef TERNARYLOGIC_SERIALIZABLE_H_
#define TERNARYLOGIC_SERIALIZABLE_H_

#include <iostream>
#include <string>
#include <vector>
#include <json/json.h>

using namespace std;


class Serializable
{
public:
	virtual ~Serializable(){}

	virtual Json::Value serialize() = 0;
	virtual void deserialize(Json::Value &node) = 0;

	virtual string save(){ return serialize().toStyledString();}
	virtual void load(string s){
		Json::Value node;
		string error;
		Json::CharReaderBuilder builder;
		Json::CharReader *reader = builder.newCharReader();
		bool success = reader->parse(s.c_str(), s.c_str() + s.size(), &node, &error);
		delete reader;
		if (success){
			deserialize(node);
		} else throw error;
	}
	
};

template<typename T>
static inline Json::Value vector_to_json(vector<T> &v){
	return vector_to_json<T>(v, [](T t) {return Json::Value(t);} );
}

template <typename T>
static inline Json::Value vector_to_json(vector<T> &v, Json::Value f(T v)){
	Json::Value jv(Json::ValueType::arrayValue);
	for (Json::ArrayIndex i = 0; i < v.size(); ++i)
	{
		jv[i] = f(v[i]);
	}
	return jv;
}

template <typename T>
static inline vector<T> json_to_vector(Json::Value &node){
	return json_to_vector<T>(node, [](Json::Value v) {return v.as<T>();});
}

template <typename T>
static inline vector<T> json_to_vector(Json::Value &node, T f(Json::Value v)){
	if(node.isArray()){
		vector<T> result(node.size());
		for (Json::ArrayIndex i = 0; i < node.size(); i++)
		{
			result[i]= f(node[i]);
		}
		return result;
	} else throw "Not an array!";
}

#endif /* TERNARYLOGIC_SERIALIZABLE_H_ */
