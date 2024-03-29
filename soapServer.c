/* soapServer.c
   Generated by gSOAP 2.8.11 from bankaccount.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapServer.c ver 2.8.11 2012-11-28 02:13:11 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap *soap)
{
#ifndef WITH_FASTCGI
	unsigned int k = soap->max_keep_alive;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (soap->max_keep_alive > 0 && !--k)
			soap->keep_alive = 0;
#endif
		if (soap_begin_serve(soap))
		{	if (soap->error >= SOAP_STOP)
				continue;
			return soap->error;
		}
		if (soap_serve_request(soap) || (soap->fserveloop && soap->fserveloop(soap)))
		{
#ifdef WITH_FASTCGI
			soap_send_fault(soap);
#else
			return soap_send_fault(soap);
#endif
		}

#ifdef WITH_FASTCGI
		soap_destroy(soap);
		soap_end(soap);
	} while (1);
#else
	} while (soap->keep_alive);
#endif
	return SOAP_OK;
}

#ifndef WITH_NOSERVEREQUEST
SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap *soap)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "account1:init"))
		return soap_serve_account1__init(soap);
	if (!soap_match_tag(soap, soap->tag, "account1:addMoney"))
		return soap_serve_account1__addMoney(soap);
	if (!soap_match_tag(soap, soap->tag, "account1:withdrawMoney"))
		return soap_serve_account1__withdrawMoney(soap);
	if (!soap_match_tag(soap, soap->tag, "account1:getAmount"))
		return soap_serve_account1__getAmount(soap);
	return soap->error = SOAP_NO_METHOD;
}
#endif

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_account1__init(struct soap *soap)
{	struct account1__init soap_tmp_account1__init;
	struct account1__initResponse soap_tmp_account1__initResponse;
	float soap_tmp_float;
	soap_default_account1__initResponse(soap, &soap_tmp_account1__initResponse);
	soap_default_float(soap, &soap_tmp_float);
	soap_tmp_account1__initResponse.result = &soap_tmp_float;
	soap_default_account1__init(soap, &soap_tmp_account1__init);
	soap->encodingStyle = NULL;
	if (!soap_get_account1__init(soap, &soap_tmp_account1__init, "account1:init", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = account1__init(soap, soap_tmp_account1__init.amount, soap_tmp_account1__initResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_account1__initResponse(soap, &soap_tmp_account1__initResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_account1__initResponse(soap, &soap_tmp_account1__initResponse, "account1:initResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_account1__initResponse(soap, &soap_tmp_account1__initResponse, "account1:initResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_account1__addMoney(struct soap *soap)
{	struct account1__addMoney soap_tmp_account1__addMoney;
	struct account1__addMoneyResponse soap_tmp_account1__addMoneyResponse;
	float soap_tmp_float;
	soap_default_account1__addMoneyResponse(soap, &soap_tmp_account1__addMoneyResponse);
	soap_default_float(soap, &soap_tmp_float);
	soap_tmp_account1__addMoneyResponse.result = &soap_tmp_float;
	soap_default_account1__addMoney(soap, &soap_tmp_account1__addMoney);
	soap->encodingStyle = NULL;
	if (!soap_get_account1__addMoney(soap, &soap_tmp_account1__addMoney, "account1:addMoney", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = account1__addMoney(soap, soap_tmp_account1__addMoney.amount, soap_tmp_account1__addMoneyResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_account1__addMoneyResponse(soap, &soap_tmp_account1__addMoneyResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_account1__addMoneyResponse(soap, &soap_tmp_account1__addMoneyResponse, "account1:addMoneyResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_account1__addMoneyResponse(soap, &soap_tmp_account1__addMoneyResponse, "account1:addMoneyResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_account1__withdrawMoney(struct soap *soap)
{	struct account1__withdrawMoney soap_tmp_account1__withdrawMoney;
	struct account1__withdrawMoneyResponse soap_tmp_account1__withdrawMoneyResponse;
	float soap_tmp_float;
	soap_default_account1__withdrawMoneyResponse(soap, &soap_tmp_account1__withdrawMoneyResponse);
	soap_default_float(soap, &soap_tmp_float);
	soap_tmp_account1__withdrawMoneyResponse.result = &soap_tmp_float;
	soap_default_account1__withdrawMoney(soap, &soap_tmp_account1__withdrawMoney);
	soap->encodingStyle = NULL;
	if (!soap_get_account1__withdrawMoney(soap, &soap_tmp_account1__withdrawMoney, "account1:withdrawMoney", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = account1__withdrawMoney(soap, soap_tmp_account1__withdrawMoney.amount, soap_tmp_account1__withdrawMoneyResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_account1__withdrawMoneyResponse(soap, &soap_tmp_account1__withdrawMoneyResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_account1__withdrawMoneyResponse(soap, &soap_tmp_account1__withdrawMoneyResponse, "account1:withdrawMoneyResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_account1__withdrawMoneyResponse(soap, &soap_tmp_account1__withdrawMoneyResponse, "account1:withdrawMoneyResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_account1__getAmount(struct soap *soap)
{	struct account1__getAmount soap_tmp_account1__getAmount;
	struct account1__getAmountResponse soap_tmp_account1__getAmountResponse;
	float soap_tmp_float;
	soap_default_account1__getAmountResponse(soap, &soap_tmp_account1__getAmountResponse);
	soap_default_float(soap, &soap_tmp_float);
	soap_tmp_account1__getAmountResponse.result = &soap_tmp_float;
	soap_default_account1__getAmount(soap, &soap_tmp_account1__getAmount);
	soap->encodingStyle = NULL;
	if (!soap_get_account1__getAmount(soap, &soap_tmp_account1__getAmount, "account1:getAmount", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = account1__getAmount(soap, soap_tmp_account1__getAmountResponse.result);
	if (soap->error)
		return soap->error;
	soap_serializeheader(soap);
	soap_serialize_account1__getAmountResponse(soap, &soap_tmp_account1__getAmountResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_account1__getAmountResponse(soap, &soap_tmp_account1__getAmountResponse, "account1:getAmountResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_account1__getAmountResponse(soap, &soap_tmp_account1__getAmountResponse, "account1:getAmountResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapServer.c */
