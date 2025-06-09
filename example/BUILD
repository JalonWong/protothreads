package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "example-small",
    srcs = ["example-small.c"],
    defines = select({
        "//:msvc": ["PT_LC_USE_SWITCH"],
        "//conditions:default": [],
    }),
    deps = [
        "//:pt",
    ],
)

cc_binary(
    name = "example-codelock",
    srcs = ["example-codelock.c"],
    defines = select({
        "//:msvc": ["PT_LC_USE_SWITCH"],
        "//conditions:default": [],
    }),
    deps = [
        "//:pt",
    ],
)

cc_binary(
    name = "example-buffer",
    srcs = ["example-buffer.c"],
    defines = select({
        "//:msvc": ["PT_LC_USE_SWITCH"],
        "//conditions:default": [],
    }),
    deps = [
        "//:pt",
    ],
)

filegroup(
    name = "examples",
    srcs = [
        ":example-small",
        ":example-codelock",
        ":example-buffer",
    ],
)
