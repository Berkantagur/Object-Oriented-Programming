#include <iostream>
using namespace std;

// CurrencyConverterError class
class CurrencyConverterError {
private:
    string message;
    int code;
public:
    CurrencyConverterError(string msg, int c) : message(msg), code(c) {}
    string what() const { return ("CurrencyConverterError !!!  Error Code:" + to_string(code)); }
    string getErrorString() const { return message; }
};

// CurrencyConverter class
class CurrencyConverter {
private:
    //variables for holding the currency names
    string currency1, currency2;
    //variables for holding the exchange values for currencies
    double currency1_value, currency2_value;

public:
    //constructor function that assing values to variables and throw exception if there is error
    CurrencyConverter(string c1, string c2, double c1_v, double c2_v){
        if(c1_v <= 0 || c2_v <= 0){
            throw CurrencyConverterError("Enxchange rate must be positive!", 1001);
        } else {
            currency1 = c1;
            currency2 = c2;
            currency1_value = c1_v;
            currency2_value = c2_v;
        }
    }
    //function for changing the exchange rate for given currency throw exception in case of error
    void ChangeExchangeRate(string currency_name, double new_rate) {
        if (new_rate <= 0){
            throw CurrencyConverterError("Exchange rate must be positive!", 1001);
        }
        if(currency_name == currency1){
            currency1_value = new_rate;
        } else if(currency_name == currency2){
            currency2_value = new_rate;
        } else {
            throw CurrencyConverterError("Invalid currency: " + currency_name, 1005);
        }
        cout << "new exchange rate for " << currency_name << " is " << new_rate << endl;
    }

    //function for converting currency from first to second given currency
    double convertCurrency(const string& fromCurrency, const string& toCurrency, double amount) {
        if (amount < 0){
            throw CurrencyConverterError("Amount must be non-negative", 1002);
        }
        if (fromCurrency == currency1){
            if(toCurrency == currency2){
                return currency1_value*amount;
            } else {
                throw CurrencyConverterError("Invalid target currency: " + toCurrency, 1003);
            }
        } else if (fromCurrency == currency2){
            if(toCurrency == currency1){
                return currency2_value*amount;
            } else {
                throw CurrencyConverterError("Invalid target currency: " + toCurrency, 1003);
            }
        } else {
            throw CurrencyConverterError("Invalid source currency: " + fromCurrency, 1004);
        }
    }
};

int main(){
    try {
        CurrencyConverter TLtoUSD("TL", "USD", 0.031, 31);

        double tlusd = TLtoUSD.convertCurrency("TL", "USD", 100);
        cout << "100 TL is " << tlusd << " USD" << endl;
        TLtoUSD.ChangeExchangeRate("JPY", 100);

        double usdtl = TLtoUSD.convertCurrency("USD", "TL", 100);
        cout << "100 USD is " << usdtl << " TL" << endl;

        double usdtojpy = TLtoUSD.convertCurrency("JPY", "USD", -100);
    }
    catch (CurrencyConverterError &e){
        cout << "CurrencyConverterError: " << e.what() << endl;
        cout << "Error Explaination:" << e.getErrorString();
    }
    catch (const exception &e){
        cout << "Exception: " << e.what() << endl;
    }
    //catch (...){
    //    cout << "An error occured!" << endl;
    //}
    return 0;
}

// Output:
// 100 TL is 3.1 USD
// CurrencyConverterError: Invalid currency: JPY
// Error Explaination: 1005