import sys
import tarfile
from glob import glob

TAMPLATE = """
`MODULE.bazel`:
```py
bazel_dep(name = "protothreads", version = "{version}")
```
"""


if __name__ == "__main__":
    tag = sys.argv[1]

    v = tag.replace("v", "")
    print(TAMPLATE.format(version=v))
    with open("MODULE.bazel", "w") as f:
        f.write(f'module(name = "protothreads", version = "{v}", compatibility_level = 1)\n\n')

    with tarfile.open(f"protothreads-{tag}.tar.gz", "w:gz") as tar:
        tar.add(".bazelrc")
        tar.add("BUILD")
        tar.add("MODULE.bazel")

        files = glob("src/**", recursive=True)
        for file in files:
            tar.add(file)
