#include "OptionsPricingModel.h"
#include "BlackScholes.h"

#include <string>


int main(int argc, const char** argv) {

	if (8 != argc) {
		printf("usage: %s cf <conversionRatio> <spotPrice> <strickPrice> <yearsToExpiry> <riskFreeInterestRate> <volatility>", argv[0]);
		printf("       %s cb <optionValue> <conversionRatio> <spotPrice> <strickPrice> <yearsToExpiry> <riskFreeInterestRate>", argv[0]);
		printf("       %s ci <optionValue> <conversionRatio> <spotPrice> <strickPrice> <yearsToExpiry> <volatility>", argv[0]);
		return 1;
	}

	BlackScholes bs;
	CallOptionValue cov(bs);
	switch (argv[1][0]) {
	case 'c':
		switch (argv[1][1]) {
		case 'f':
			printf("%lf\r\n", cov.value(std::stod(argv[3]), std::stod(argv[4]), std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]), 0.0) / std::stod(argv[2]));
			break;

		case 'b':
			printf("%lf\r\n", cov.impliedVolatility(std::stod(argv[3]) * std::stod(argv[2]), std::stod(argv[4]), std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]), 0.0));
			break;

		case 'i':
			printf("%lf\r\n", cov.impliedInterestRate(std::stod(argv[3]) * std::stod(argv[2]), std::stod(argv[4]), std::stod(argv[5]), std::stod(argv[6]), std::stod(argv[7]), 0.0));
			break;
		}
		break;
	}

	return 0;
}