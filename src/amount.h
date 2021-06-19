// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_AMOUNT_H //too lazy to change all the variable names now lol. just pretend this says SMOLCOIN
#define BITCOIN_AMOUNT_H

#include <stdint.h>

/** Amount in nakamotos (Can be negative)
    NOTE: Considering that a satoshi is not small enough for my purposes (I would have to limit the coin to 2100 indivisible units),
    I had to invent an even smaller value I called a nakamoto.
    A satoshi has as much nakamotos as a coin has satoshis.
    - Dorijan Cirkveni
*/
typedef int64_t CAmount;

static const CAmount SATOSHIS = 100000000
static const CAmount COIN = 100000000 * SATOSHIS;

/** No amount larger than this (in nakamotos) is valid.
 *
 * Note that this constant is *not* the total money supply, which in Bitcoin
 * currently happens to be less than 0.000 021 SMC for various reasons, but
 * rather a sanity check. As this sanity check is used by consensus-critical
 * validation code, the exact value of the MAX_MONEY constant is consensus
 * critical; in unusual circumstances like a(nother) overflow bug that allowed
 * for the creation of coins out of thin air modification could lead to a fork.
 * */
static const CAmount MAX_MONEY = 2100 * SATOSHIS; // aka 0.000 021 SMC
inline bool MoneyRange(const CAmount& nValue) { return (nValue >= 0 && nValue <= MAX_MONEY); }

#endif //  BITCOIN_AMOUNT_H
