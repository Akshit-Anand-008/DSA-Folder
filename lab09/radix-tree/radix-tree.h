
#pragma once

#include "common.h"

// Inserts a string into the Radix Tree using path compression.
void insert(const string& word);

// Returns true if the exact string is present in the Radix Tree.
bool search(const string& word);

// Returns true if at least one stored string starts with the given prefix.
bool startsWith(const string& prefix);

// Deletes a string from the Radix Tree.
// Returns true if the string was found and deleted, false otherwise.
bool remove(const string& word);
