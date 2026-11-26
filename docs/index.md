# Timer Contract guide

A timestamp is a position in a modulo counter. Elapsed arithmetic has a unique answer only within one full counter period. Read the counter width and wrap semantics before comparing timestamps or applying optional clock controls.

1. Start with [the contract](contract.md) for implementer obligations and capability boundaries.
2. Read [the conformance example](examples.md) for an implementation you can compile locally.
3. Consult [the portability notes](compatibility.md) before choosing a hardware mapping.