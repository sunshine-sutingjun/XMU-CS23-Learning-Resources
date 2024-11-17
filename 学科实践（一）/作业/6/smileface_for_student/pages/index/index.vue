<!-- 本案例为笑脸的素材 
运行时通过修改机型来观察运行结果
考察：uni-app中的尺寸单位，Canvas，绘图API：uni.canvasToTempFilePath，
uni.getSystemInfoSync().windowWidth
以及CanvasContext的相关操作。
对应的，smileface项目的CanvasInRpx.vue为完成版本
-->
<!-- 本页面完成笑脸的制作 
考察：尺寸单位，Canvas，图片写文件等
-->
<template>
	<view class="Cont">
		<view>
			<canvas canvas-id="mycanvas" class="mycanvas" :style="{ width: w + 'rpx', height: h + 'rpx' }"
				@error="canvasErrorHandler"></canvas>
		</view>
	</view>
</template>

<script>
export default {
	data() {
		return {
			w: 400,
			h: 400,
			rate_rpx2px: 1,
			LineWidth: 8
		}
	},
	onLoad() {
		//参考资料：https://uniapp.dcloud.net.cn/uni-app-x/api/get-system-info.html#getsysteminfosync
		this.calculateRate();
	},
	onReady() {
		this.drawCanvas();
	},
	methods: {
		calculateRate() {
			this.rate_rpx2px = uni.getSystemInfoSync().windowWidth / 750; // 1rpx = ?px
			// console.log(this.rate_rpx2px);
		},
		drawCanvas() {
			const context = uni.createCanvasContext('mycanvas');
			//任务1：画一个矩形边框
			this.drawRectangle(context);
			//任务2：画脸的边缘
			this.drawFaceEdge(context);
			//任务3：画嘴巴
			this.drawMouth(context);
			//任务4：画两只眼睛
			this.drawEyes(context);
			context.draw();
			this.saveCanvasToFile();
		},
		drawRectangle(context) {
			context.beginPath();
			context.setStrokeStyle("#007aff");
			var lw = this.LineWidth * this.rate_rpx2px;
			context.setLineWidth(lw);
			context.rect(0, 0, this.w * this.rate_rpx2px, this.h * this.rate_rpx2px);
			context.stroke();
		},
		drawFaceEdge(context) {
			context.beginPath();
			context.setStrokeStyle("#ff0000");
			this.EllipseOne(context, this.w * this.rate_rpx2px / 2, this.h * this.rate_rpx2px / 2, this.w * this.rate_rpx2px / 2 * 0.75, this.h * this.rate_rpx2px / 2 * 0.75);
			context.stroke();
		},
		drawMouth(context) {
			context.beginPath();
			context.arc(this.w * this.rate_rpx2px / 2, this.h * this.rate_rpx2px / 2, this.w * this.rate_rpx2px / 2 * 0.5, 0, Math.PI);
			context.stroke();
		},
		drawEyes(context) {
			context.beginPath();
			context.arc(this.w * this.rate_rpx2px * 0.5 * 0.8, this.h * this.rate_rpx2px * 0.5 * 0.8, this.w * this.rate_rpx2px * 0.03, 0, 2 * Math.PI);
			context.stroke();
			context.closePath();
			context.beginPath();
			context.arc(this.w * 0.5 * 1.2 * this.rate_rpx2px, this.h * this.rate_rpx2px * 0.5 * 0.8, this.w * this.rate_rpx2px * 0.03, 0, 2 * Math.PI);
			context.stroke();
		},
		saveCanvasToFile() {
			uni.canvasToTempFilePath({
				x: 0,
				y: 0,
				width: this.w * this.rate_rpx2px,
				height: this.h * this.rate_rpx2px,
				destWidth: this.w * this.rate_rpx2px,
				destHeight: this.h * this.rate_rpx2px,
				canvasId: 'mycanvas',
				success: function (res) {
					console.log("tempFilePath: " + res.tempFilePath);
				}
			});
		},
		canvasErrorHandler(e) {
			console.error(e.detail.errMsg);
		},
		EllipseOne(context, cx, cy, rx, ry) {
			var kappa = 1.1522848;
			var ox = (rx * kappa) / 2;
			var oy = (ry * kappa) / 2;

			context.moveTo(cx - rx, cy);
			context.bezierCurveTo(cx - rx, cy - oy, cx - ox, cy - ry, cx, cy - ry);
			context.bezierCurveTo(cx + ox, cy - ry, cx + rx, cy - oy, cx + rx, cy);
			context.bezierCurveTo(cx + rx, cy + oy, cx + ox, cy + ry, cx, cy + ry);
			context.bezierCurveTo(cx - ox, cy + ry, cx - rx, cy + oy, cx - rx, cy);
		}
	}
}
</script>

<style>
.Cont {
	box-sizing: border-box;
}

.mycanvas {
	background: orange;
	margin: 100rpx auto;
}
</style>
