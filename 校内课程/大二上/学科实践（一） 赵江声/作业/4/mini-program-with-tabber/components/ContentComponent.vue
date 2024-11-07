<template> 
	<view class="content"> 
		<image class="logo" :src="imgsrc"></image> 
		<view class="text-area"> 
			<text class="title">{{ title }}</text> 
		</view> 
	</view> 
	<view class="uni-padding-wrap uni-common-mt"> 
		<button type="primary" v-on:click="NavigateToWindows">Next</button> 
	</view> 
</template> 
 
<script> 
	export default { 
		props: { 
			imgsrc: { 
				type: String, 
				required: true 
			}, 
			title: { 
				type: String, 
				required: true 
			},
			url: { 
				type: String, 
				required: true 
			}
		}, 
		methods: { 
			NavigateToWindows() { 
				uni.switchTab({ 
					url: this.url  // 使用传入的 URL
				}) 
			} 
		} 
	} 
</script> 
 
<style> 
	.content { 
		display: flex; 
		flex-direction: column; 
		align-items: center; 
		justify-content: center; 
	} 
 
	.logo { 
		height: 200rpx; 
		width: 200rpx; 
		margin-top: 200rpx; 
		margin-left: auto; 
		margin-right: auto; 
		margin-bottom: 50rpx; 
	} 
 
	.text-area { 
		display: flex; 
		justify-content: center; 
		margin: 20rpx; 
	} 
 
	.title { 
		font-size: 36rpx; 
		color: #aaaa7f; 
		white-space: pre-line;
	} 
</style> 
