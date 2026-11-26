# Porting the Timer Contract

Hardware Definitions can describe native counter width, clock routes, compare channels and event input routing. The Adapter maps those facilities into the interfaces and documents clock choices, capture overrun behavior and coherency of multi-byte observations. Fixed-rate and externally clocked counters can supply the base alone. Down-counting and a programmable modulus are outside this contract.

This repository's host simulations and shared API compile/link checks provide source-level evidence. Target timing and physical behavior require hardware validation.
