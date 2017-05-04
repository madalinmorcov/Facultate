#include "DiscountRate.h"

double DiscountRate::getServiceDiscountRate(std::string memberType) {
	if (memberType.compare("Premium"))
		return serviceDiscountPremium;
	else if (memberType.compare("Gold"))
		return serviceDiscountGold;
	else if (memberType.compare("Silver"))
		return serviceDiscountSilver;
	else
		return -1;
}

double DiscountRate::getProductDiscountRate(std::string memberType)
{
	if (memberType.compare("Premium"))
		return productDiscountPremium;
	else if (memberType.compare("Gold"))
		return productDiscountGold;
	else if (memberType.compare("Silver"))
		return productDiscountSilver;
	else
		return -1;
}
