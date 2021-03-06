/*
 * Copyright (C) 2016 Linaro.
 * Viresh Kumar <viresh.kumar@linaro.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/err.h>
#include <linux/of.h>
#include <linux/platform_device.h>

static const struct of_device_id machines[] __initconst = {
	{ .compatible = "fsl,imx27", },
	{ .compatible = "fsl,imx51", },
	{ .compatible = "fsl,imx53", },
	{ .compatible = "fsl,imx7d", },

	{ .compatible = "marvell,berlin", },

	{ .compatible = "samsung,exynos3250", },
	{ .compatible = "samsung,exynos4210", },
	{ .compatible = "samsung,exynos4212", },
	{ .compatible = "samsung,exynos4412", },
	{ .compatible = "samsung,exynos5250", },
#ifndef CONFIG_BL_SWITCHER
	{ .compatible = "samsung,exynos5420", },
	{ .compatible = "samsung,exynos5800", },
#endif

	{ .compatible = "rockchip,rk2928", },
	{ .compatible = "rockchip,rk3036", },
	{ .compatible = "rockchip,rk3066a", },
	{ .compatible = "rockchip,rk3066b", },
	{ .compatible = "rockchip,rk3188", },
	{ .compatible = "rockchip,rk3228", },
	{ .compatible = "rockchip,rk3288", },
	{ .compatible = "rockchip,rk3366", },
	{ .compatible = "rockchip,rk3368", },
	{ .compatible = "rockchip,rk3399", },

	{ .compatible = "ti,omap2", },
	{ .compatible = "ti,omap3", },
	{ .compatible = "ti,omap4", },
	{ .compatible = "ti,omap5", },
};

static int __init cpufreq_dt_platdev_init(void)
{
	struct device_node *np = of_find_node_by_path("/");

	if (!np)
		return -ENODEV;

	if (!of_match_node(machines, np))
		return -ENODEV;

	of_node_put(of_root);

	return PTR_ERR_OR_ZERO(platform_device_register_simple("cpufreq-dt", -1,
							       NULL, 0));
}
device_initcall(cpufreq_dt_platdev_init);
