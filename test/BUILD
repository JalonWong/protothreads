cc_test(
    name = "unit_test",
    srcs = glob([
        "*.cc",
        "*.hh",
    ]),
    copts = select({
        "//:msvc": ["/utf-8"],
        "//conditions:default": [],
    }),
    includes = [
        ".",
    ],
    deps = [
        "//:pt",
        "@googletest//:gtest_main",
    ],
    visibility = ["//visibility:public"],
)
