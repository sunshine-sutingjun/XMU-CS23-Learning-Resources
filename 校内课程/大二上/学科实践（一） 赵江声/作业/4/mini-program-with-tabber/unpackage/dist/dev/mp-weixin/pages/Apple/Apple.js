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
      imgsrc: "/static/Apple.png",
      title: "给人带来了奇妙的体验\n			曾经的辉煌仍在继续\n			但是。。。",
      url: "/pages/Huawei/Huawei"
    })
  };
}
const MiniProgramPage = /* @__PURE__ */ common_vendor._export_sfc(_sfc_main, [["render", _sfc_render]]);
wx.createPage(MiniProgramPage);
