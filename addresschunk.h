#ifndef ADDRESSCHUNK_H_INCLUDED
#define ADDRESSCHUNK_H_INCLUDED

#include "addresslist.h"
#include "stringchunk.h"
#include "querydnsbase.h"

typedef struct _AddressChunk{
	AddressList	TCPAddresses;
	AddressList	UDPAddresses;

	StringChunk	Dedicated;
} AddressChunk;

int AddressChunk_Init(AddressChunk *ac, int NumberOfDedicated);

int AddressChunk_AddATCPAddress_FromString(AddressChunk *ac, const char *Addr_Port);

int AddressChunk_AddAUDPAddress_FromString(AddressChunk *ac, const char *Addr_Port);

int AddressChunk_AddADedicatedAddress_FromString(AddressChunk *ac, const char *Domain, const char *Addr_Port);

struct sockaddr *AddressChunk_GetOne(AddressChunk *ac, sa_family_t *family, const char *RequestingDomain, int *HashValue, DNSQuaryProtocol Protocol);

int AddressChunk_Advance(AddressChunk *ac, DNSQuaryProtocol Protocol);

#endif // ADDRESSCHUNK_H_INCLUDED
