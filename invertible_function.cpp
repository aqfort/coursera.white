#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class FunctionPart {
public:
    FunctionPart(char new_operation, double new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(double source_value) const {
        switch (operation) {
            case '+':
                return source_value + value;
            case '-':
                return source_value - value;
            case '*':
                return source_value * value;
            default:
                return source_value / value;
        }
    }

    void Invert() {
        switch (operation) {
            case '+':
                operation = '-';
                break;
            case '-':
                operation = '+';
                break;
            case '*':
                operation = '/';
                break;
            default:
                operation = '*';
        }
    }

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(char operation, double value) {
        parts.emplace_back(operation, value);
    }

    double Apply(double value) const {
        for (const FunctionPart &part : parts) {
            value = part.Apply(value);
        }
        return value;
    }

    void Invert() {
        for (FunctionPart &part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }

private:
    vector<FunctionPart> parts;
};

struct Image {
    double quality;
    double freshness;
    double rating;
};

struct Params {
    double a;
    double b;
    double c;
};

Function MakeWeightFunction(const Params &params,
                            const Image &image) {
    Function function;
    function.AddPart('*', params.a);
    function.AddPart('-', image.freshness * params.b);
    function.AddPart('+', image.rating * params.c);
    return function;
}

double ComputeImageWeight(const Params &params, const Image &image) {
    Function function = MakeWeightFunction(params, image);
    return function.Apply(image.quality);
}

double ComputeQualityByWeight(const Params &params,
                              const Image &image,
                              double weight) {
    Function function = MakeWeightFunction(params, image);
    function.Invert();
    return function.Apply(weight);
}

int main() {
    Image image = {10, 2, 6};
    Params params = {4, 2, 6};
    cout << ComputeImageWeight(params, image) << endl;
    cout << ComputeQualityByWeight(params, image, 52) << endl;
    return 0;
}