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
      imgsrc: "/static/logo.png",
      title: "故事的发生是这样的...",
      url: "/pages/Windows/Windows"
    })
  };
}
const MiniProgramPage = /* @__PURE__ */ common_vendor._export_sfc(_sfc_main, [["render", _sfc_render]]);
wx.createPage(MiniProgramPage);
