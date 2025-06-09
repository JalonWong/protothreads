config_setting(
    name = "msvc",
    flag_values = {"@bazel_tools//tools/cpp:compiler": "msvc-cl"},
)

config_setting(
    name = "use_switch",
    define_values = {"pt_option": "lc_switch"},
)

cc_library(
    name = "pt",
    hdrs = glob(["src/pt/*.h"]),
    defines = select({
        ":use_switch": ["PT_LC_USE_SWITCH"],
        "//conditions:default": [],
    }),
    includes = [
        "src",
    ],
    visibility = ["//visibility:public"],
)
