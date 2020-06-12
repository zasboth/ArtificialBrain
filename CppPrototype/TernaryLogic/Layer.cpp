/*
 * Layer.cpp
 *
 *  Created on: 2020. jún. 11.
 *      Author: zsolt
 */

#include <Layer.h>

template<class T>
Layer<T>::Layer(int inputLength_, int outputLength_) :
		AbstarctContainer(inputLength_, outputLength_), neurons(outputLength_) {
	for (int i = 0; i < neurons.size(); ++i) {
		neurons[i] = T(inputLength_);
	}
}

template<class T>
Layer<T>::~Layer() {
}

template<class T>
void Layer<T>::teach(bool correct) {
	for (auto item : neurons) {
		item.teach(correct);
	}
}

template<class T>
vector<double, allocator<double>> Layer<T>::askAnalog(const vector<double> &d) {
	vector<double> result(outputLengt);
	for (int i = 0; i < neurons.size(); ++i) {
		result[i] = neurons[i].askAnalog(d[0]);
	}
	return result;
}

template<class T>
Pebble Layer<T>::askTernary(const Pebble &p) {
	Pebble result(outputLengt);
	for (int i = 0; i < neurons.size(); ++i) {
		result[i] = neurons[i].askTernary(p);
	}
	return result;
}

template<class T>
vector<double, allocator<double>> Layer<T>::askAnalog(const Pebble &p) {
	vector<double> result(outputLengt);
	for (int i = 0; i < neurons.size(); ++i) {
		result[i] = neurons[i].askTernary(p);
	}
	return result;
}

template<class T>
Pebble Layer<T>::askTernary(const vector<double> &d) {
	Pebble result(outputLengt);
	for (int i = 0; i < neurons.size(); ++i) {
		result[i] = neurons[i].askAnalog(d[0]);
	}
	return result;
}
