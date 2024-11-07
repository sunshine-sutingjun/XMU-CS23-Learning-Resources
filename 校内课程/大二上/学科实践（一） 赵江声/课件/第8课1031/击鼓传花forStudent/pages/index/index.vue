<!-- 本例目标： 
实现方块在一个区域里的顺时针的移动，从左上方到达中心点
-->

<template>
	<view class="">
		<view :class="classContain1Obj">
			<view :class="[]">{{pointer}}</view>
		</view>
		<button type="default" @click="TurnRound()">击鼓传花</button>
	</view>
</template>

<script>
	export default {
		data() {
			return {
				pointer: 0,
				classcontainer1: "container1",
				classContain1Obj : ""
			}
		},
		onLoad() {
			this.classContain1Obj = this.classcontainer1
		},
		methods: {
			TurnRound() {


				
				
				
			}
		}
	}
</script>

<style>
	
	.container {
		display: flex;
		flex-direction: row;

		margin: 10px;
	}

	.container1 {
		display: flex;

		width: 600rpx;
		height: 600rpx;
		background-color: beige;

		margin: 10rpx auto;

	}


	

	.box1 {
		width: 200rpx;
		height: 200rpx;
		background-color: fuchsia;

	}

	
</style>