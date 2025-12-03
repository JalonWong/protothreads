package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "example-small",
    srcs = ["example-small.c"],
    deps = [
        "//:pt",
    ],
)

cc_binary(
    name = "example-codelock",
    srcs = ["example-codelock.c"],
    deps = [
        "//:pt",
    ],
)

cc_binary(
    name = "example-buffer",
    srcs = ["example-buffer.c"],
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
