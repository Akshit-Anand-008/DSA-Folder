#pragma once
#include "common.h"

// Removes every inserted copy of `pattern` from the linked list, in place,
// `delete`-ing every node that belongs to a removed copy, and returns the
// length of the recovered sequence. After the call, `head` points to the
// first node of the recovered chromosome (or is nullptr if the whole list
// was contaminant). Every node reachable from `head` afterwards belongs to
// the recovered chromosome -- there is no "leftover tail" to ignore, unlike
// the array version from Lab 02.
int recover_original(Node *&head, const string &pattern);
