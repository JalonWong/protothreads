# Port Protothreads as a Bazel Module

The source code comes from [Adam Dunkels' Protothreads](https://dunkels.com/adam/pt/).

## Getting Started
`MODULE.bazel`
```py
bazel_dep(name = "protothreads", version = "<version>")
```
See [Releases](https://github.com/JalonWong/protothreads/releases)

`BUILD`
```py
cc_binary(
    ...
    deps = [
        "@protothreads//:pt",
    ],
)
```

`main.c`
```c
#include <pt/pt.h>

PT_THREAD(thread1(pt_t *pt)) {
    PT_BEGIN(pt);
    PT_END(pt);
}

int main() {
    pt_t pt_1;
    PT_INIT(&pt_1);

    while (PT_SCHEDULE(thread1(&pt_1))) {
    }
    return 0;
}
```
See also [example](example).

### Optional
Uses the C `switch()` statement to resume execution of a function
```sh
bazel build --define=pt_option=lc_switch app
```

## Development
```sh
bazel build //example:examples
bazel test //test:unit_test
# For MSVC
bazel test --config=msvc //test:unit_test
```
