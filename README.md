## Initialization

The first step is to initialize the workspace folder (`zephyr_demo`) where the `standalone-inferencing-zephyr` and all Zephyr modules will be cloned. You can do that by running:

```bash
# initialize my-workspace for the example-application (main branch)
west init -m git@github.com:edgeimpulse/example-standalone-inferencing-zephyr.git --mr demo_struct zephyr_demo
# update Zephyr modules
cd my-workspace
west update
```

After doing `west update` we will see that all is updated to the specific version into the `zephyr_demo` folder. If for example `revision` of something is updated you must do the `west update` command again.
