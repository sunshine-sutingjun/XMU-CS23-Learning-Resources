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
      imgsrc: "/static/Windows.png",
      title: "一个伟大的帝国，但早已离我们远去。。。",
      url: "/pages/Apple/Apple"
    })
  };
}
const MiniProgramPage = /* @__PURE__ */ common_vendor._export_sfc(_sfc_main, [["render", _sfc_render]]);
wx.createPage(MiniProgramPage);
