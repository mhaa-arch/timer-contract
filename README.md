# MHAA Timer Contract

Defines an up counter with a native width and wrap in ticks. Independent capabilities expose an adjustable nominal tick rate, compare thresholds and event captures.

Implement the wrapping up counter first. Clock, compare and capture can be supplied selectively.

## Where it fits

The Timer Contract defines the interface and observable behavior. A concrete MCU Adapter implements it using Hardware Definitions. The Core consumes a reference to the implementation. Future Devices will bind the selected Adapter to the Core for the application. This project depends on C++11 standard headers.

Add `include/` to the C++11 include path and start with `<timer/counter.hpp>`. The [technical guide](docs/index.md) covers the other public interfaces and integration obligations.

- [Interface semantics](docs/contract.md)
- [Portability and limits](docs/compatibility.md)
- [Worked example and build commands](docs/examples.md)
- [MIT License](LICENSE)

## Generate the API reference

Use Doxygen 1.18.0. From this repository root, create `build/` if it does not exist, then run `doxygen Doxyfile`.

```sh
mkdir -p build
doxygen Doxyfile
```

On PowerShell, use `New-Item -ItemType Directory -Force build` for the first command. Open `build/docs/html/index.html`. Mermaid diagrams render in a browser with access to the Mermaid CDN. GitHub Pages publication runs on published releases and on manual dispatches from `main` once Pages is enabled.
