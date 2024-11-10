"use strict";
const common_vendor = require("../../common/vendor.js");
const ContentComponent = () => "../../components/ContentComponent.js";
const _sfc_main = {
  components: {
    ContentComponent
  }
};
if (!Array) {
  const _component_ContentComponent = common_vendor.resolveComponent("ContentComponent");
  _component_ContentComponent();
}
function _sfc_render(_ctx, _cache, $props, $setup, $data, $options) {
  return {
    a: common_vendor.p({
      imgsrc: "/static/Huawei.png",
      title: "没有伤痕累累，\n			哪来皮糙肉厚，\n			英雄自古多磨难。\n			回头看，\n			崎岖坎坷；\n			向前看，\n			永不言弃。",
      url: "/pages/index/index"
    })
  };
}
const MiniProgramPage = /* @__PURE__ */ common_vendor._export_sfc(_sfc_main, [["render", _sfc_render]]);
wx.createPage(MiniProgramPage);
